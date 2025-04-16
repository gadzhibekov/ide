#include "translator.h"

QString                     Translator::current_language    = "";
std::vector<QString>        Translator::current_language_data_set;

Translator::Translator(const QString& language)
{
    Translator::current_language = language;

    std::vector<QString> leki_data_set = 
    {
        "Кнопкадал элис",
        "директория ахъагъун патал",
        "ЭКСПЛОРЕР:",
        "Эхиримжи директория загрузка айидан ?",
        "Ваъ, ийимир",
        "Загрузка ая",
        "Файл чlурдан ?",
        "Ваъ, чlурмир",
        "Эхь, чlура",
        "Программа хкудна кутур",
        "Дигишвилер жеда программа хкудна кутурхъувула\n\nПрограммадин чlал дегиш жеда\n",
        "Ахпа",
        "Хкудна кутур",
        "Директория хкягъа",
        "Хьурай",
        "Лезги",
        "Урус",
        "Английский",
        " чlалал"
    };

    std::vector<QString> ru_data_set = 
    {
        "Нажмите на кнопку",
        "для того чтобы открыть директорию",
        "ЭКСПЛОРЕР: ",
        "Загрузить последнюю директорию",
        "Закрыть",
        "Загрузить",
        "Удалить файл ?",
        "Отмена",
        "Удалить",
        "Перезагрузить программу",
        "Изменения вступят в силу после перезагрузки\n\nПрограмма будет переведена на\n",
        "Потом",
        "Перезагрузить",
        "Выберите директорию",
        "OK",
        "Лезгинский",
        "Русский",
        "Английский",
        " язык"
    };

    std::vector<QString> en_data_set = 
    {
        "Click the button",
        "to open the directory",
        "EXPLORER: ",
        "Load the last directory",
        "Close",
        "Load",
        "Delete file ?",
        "Cancel",
        "Delete",
        "Restart the program",
        "The changes will take effect after reboot\n\nThe program will be translated to ",
        "Later",
        "Restart",
        "Select directory",
        "OK",
        "Lezgi",
        "Russian",
        "English",
        " language"
    };

    if (language == "ru")       current_language_data_set = ru_data_set;
    if (language == "en")       current_language_data_set = en_data_set;
    if (language == "leki")     current_language_data_set = leki_data_set;
}