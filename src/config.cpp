#include "config.h"

#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>

#include <iostream>
#include <cstdlib>

ConfigData::ConfigData(std::pair<QString, QString> config_data) : last_project_dir(config_data.first), language(config_data.second) {}

ConfigData Config::read()
{
    if (!(QFile(STANDART_TEMP_DIR + static_cast<QString>(CONFIG_FILE_NAME)).exists()))
    {
        QString command = static_cast<QString>("touch ") + STANDART_TEMP_DIR + static_cast<QString>(CONFIG_FILE_NAME);

        std::system(command.toStdString().c_str());

        return ConfigData({"", LEKI});
    }

    QString file_path = STANDART_TEMP_DIR + static_cast<QString>(CONFIG_FILE_NAME);
    QFile file(file_path);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        QByteArray      data = file.readAll();
        QJsonDocument   doc  = QJsonDocument::fromJson(data);

        if (doc.isObject()) 
        {
            QJsonObject obj       = doc.object();
            QString     directory = obj["directory"].toString();
            QString     language  = obj["language"].toString();

            if (!(QDir(directory).exists()))                                directory = "";
            if (!(language == RU || language == EN || language == LEKI))    language  = LEKI;

            return ConfigData({directory, language});
        }

        file.close();
    }

    return ConfigData({"", LEKI});
}

void Config::write(ConfigData&& config_data)
{
    QJsonObject obj;
    
    obj["directory"] = static_cast<QString>(config_data.last_project_dir);
    obj["language"]  = static_cast<QString>(config_data.language);

    QJsonDocument doc(obj);
    QFile file(STANDART_TEMP_DIR + static_cast<QString>(CONFIG_FILE_NAME));

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) 
    {
        file.write(doc.toJson());
        file.close();
    }
}