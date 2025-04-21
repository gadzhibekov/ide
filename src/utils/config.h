#ifndef CONFIG_H
#define CONFIG_H

#define STANDART_TEMP_DIR   QStandardPaths::writableLocation(QStandardPaths::TempLocation)
#define CONFIG_FILE_NAME    "/ide_configuration.json"
#define LEKI                "leki"
#define RU                  "ru"
#define EN                  "en"

#include <QStandardPaths>
#include <QString>

#include <unistd.h>

struct ConfigData
{
    ConfigData(std::pair<QString, QString> config_data);

    QString                     last_project_dir;
    QString                     language;
};

struct Config
{
    static  void                write(ConfigData&& config_data);
    static  ConfigData          read();
};

#endif // CONFIG_H