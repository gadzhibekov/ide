#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>
#include <QString>

struct Label : QLabel
{
    Label(QWidget* parent);

    void        set_text(const QString& text)   { this->setText(text); }

    QString     get_text() const                { return this->text(); }
};

#endif // LABEL_H