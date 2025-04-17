#include "config.h"

#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>

#include <iostream>
#include <cstdlib>

ConfigData::ConfigData(std::pair<QString, QString> config_data) : last_project_dir(config_data.first), language(config_data.second) {}

QString Config::get_standart_temp_path() 
{ 
    return QStandardPaths::writableLocation(QStandardPaths::TempLocation);
}

ConfigData Config::read()
{
    if (!(QFile(get_standart_temp_path() + CONFIG_FILE_NAME).exists()))
    {
        QString command = "touch " + get_standart_temp_path() + CONFIG_FILE_NAME;

        std::system(command.toStdString().c_str());

        return ConfigData({"", "leki"});
    }

    QString file_path = get_standart_temp_path() + CONFIG_FILE_NAME;
    QFile file(file_path);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        QByteArray      data    = file.readAll();
        QJsonDocument   doc     = QJsonDocument::fromJson(data);

        if (doc.isObject()) 
        {
            QJsonObject obj         = doc.object();
            QString     directory   = obj["directory"].toString();
            QString     language    = obj["language"].toString();

            if (!(QDir(directory).exists()))                                        directory   = "";
            if (!(language == "ru" || language == "en" || language == "leki"))      language    = "leki";

            return ConfigData({directory, language});
        }

        file.close();
    }

    return ConfigData({"", "leki"});
}

void Config::write(ConfigData&& config_data)
{
    QJsonObject obj;
    
    obj["directory"]    = static_cast<QString>(config_data.last_project_dir);
    obj["language"]     = static_cast<QString>(config_data.language);

    QJsonDocument doc(obj);
    QFile file(get_standart_temp_path() + CONFIG_FILE_NAME);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) 
    {
        file.write(doc.toJson());
        file.close();
    }
}