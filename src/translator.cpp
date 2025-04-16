#include "translator.h"

QString                     Translator::current_language    = "";
std::vector<QString>        Translator::current_language_data_set;

Translator::Translator(const QString& language)
{
    Translator::current_language = language;

    std::vector<QString> ru_data_set = 
    {
        "Нажмите на кнопку",
        "для того чтобы открыть директорию",
        "ЭКСПЛОРЕР: ",
        "Загрузить последнюю директорию",
        "Закрыть",
        "Загрузить",
        "Удалить файл",
        "Отмена",
        "Удалить",
        "Перезагрузить программу",
        "Изменения вступят в силу после перезагрузки",
        "Потом",
        "Перезагрузить",
        "Выберите директорию",
        "OK"
    };

    std::vector<QString> en_data_set = 
    {
        "Click the button",
        "to open the directory",
        "EXPLORER: "
        "Load the last directory",
        "Close",
        "Load",
        "Delete file",
        "Cancel",
        "Delete",
        "Restart the program",
        "Changes will take effect after restart",
        "Later",
        "Restart",
        "Select directory",
        "OK"
    };

    std::vector<QString> leki_data_set = 
    {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };

    if (language == "ru")       current_language_data_set   = ru_data_set;
    if (language == "en")       current_language_data_set   = en_data_set;
    if (language == "leki")     current_language_data_set   = leki_data_set;
}