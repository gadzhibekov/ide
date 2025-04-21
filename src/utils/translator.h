#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QString>

#include <vector>

struct Translator
{
    Translator(const QString& language);

    static QString                  current_language;
    static std::vector<QString>     current_language_data_set;

private:
    std::vector<QString>            ru_data_set;
    std::vector<QString>            en_data_set;
    std::vector<QString>            leki_data_set;
};

#endif // TRANSLATOR_H