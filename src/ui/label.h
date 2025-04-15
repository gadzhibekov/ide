#ifndef LABEL_H
#define LABEL_H

#include <QWidget>
#include <QLabel>
#include <QString>

struct Label : QLabel
{
    Label(QWidget* parent);

    void        set_text(const QString& text);
    void        set_text_size(int size);
    void        set_icon(const QString& path);
    void        set_icon_size(int width, int height);
    void        set_geometry(int x, int y, int w, int h);

    QString     get_text() const { return this->text(); }
    
};

#endif // LABEL_H