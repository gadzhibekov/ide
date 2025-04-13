#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>
#include <QString>

struct Label : QLabel
{
    Label(QWidget* parent);

    void        set_text(const QString& text)                   { this->setText(text); }
    void        set_geometry(int x, int y, int w, int h);

    QString     get_text() const                                { return this->text(); }
    
};

#endif // LABEL_H