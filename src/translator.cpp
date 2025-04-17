#include "translator.h"

QString                     Translator::current_language            = "";
std::vector<QString>        Translator::current_language_data_set;

Translator::Translator(const QString& language)
{
    Translator::current_language        = language;

    std::vector<QString> leki_data_set = 
    {
        "Кнопкадал элис",
        "директория ахъагъун патал",
        "ПРОВОДНИК:",
        "Эхиримжи директория загрузка айидан ?",
        "Ваъ, ийимир",
        "Загрузка ая",
        "Файл чlурдан ?",
        "Ваъ, чlурмир",
        "Эхь, чlура",
        "Программа хкудна кутур",
        "Дигишвилер жеда программа хкудна \nкутурхъувула\nПрограммадин чlал дегиш жеда\n",
        "Ахпа",
        "Хкудна кутур",
        "Директория хкягъа",
        "Хьурай",
        "Лезги",
        "Урус",
        "Английский",
        " чlалал",
        "Чlал дегишарун",
        "Файл жагъанач",
        "И файл чlурнвай файл я\nСадра мад кнопкадал элис \nгьам проводникдай чlур айидайвал",
        "Агал", 
        "Садра мад"
    };

    std::vector<QString> ru_data_set = 
    {
        "Нажмите на кнопку",
        "для того чтобы открыть директорию",
        "ПРОВОДНИК: ",
        "Загрузить последнюю директорию",
        "Закрыть",
        "Загрузить",
        "Удалить файл ?",
        "Отмена",
        "Удалить",
        "Перезагрузить программу",
        "Изменения вступят в силу после \nперезагрузки\nПрограмма будет переведена на\n",
        "Потом",
        "Перезагрузить",
        "Выберите директорию",
        "OK",
        "Лезгинский",
        "Русский",
        "Английский",
        " язык",
        "Смена языка", 
        "Файл не найден",
        "Этот файл был удален\nНажмите на кнопку обновить \nдля того чтобы убрать его из проводника",
        "Закрыть", 
        "Обновить"
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
        "The changes will take effect after reboot\n\nThe program will be translated to\n",
        "Later",
        "Restart",
        "Select directory",
        "OK",
        "Lezgi",
        "Russian",
        "English",
        " language",
        "Change of language",
        "File is not found",
        "This file has been deleted\nClick the refresh button to remove \nit from the explorer",
        "Close",
        "Refresh"
    };

    if (language == "ru")       current_language_data_set = ru_data_set;
    if (language == "en")       current_language_data_set = en_data_set;
    if (language == "leki")     current_language_data_set = leki_data_set;
}