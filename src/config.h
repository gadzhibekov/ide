#ifndef CONFIG_H
#define CONFIG_H

#define CONFIG_FILE_NAME "/ide_configuration.json"

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
    static  QString             get_standart_temp_path();
};

#endif // CONFIG_H