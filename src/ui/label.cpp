#include "label.h"

#include <QFont>
#include <QPixmap>
#include <QColor>
#include <QPalette>

Label::Label(QWidget* parent) : QLabel(parent)
{
    
}

void Label::set_geometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);
}

void Label::set_text(const QString& text) 
{ 
    this->setText(text); 
}

void Label::set_icon(const QString& path)
{
    QPixmap pixmap(path);

    this->setPixmap(pixmap);
    this->setScaledContents(true);
    this->resize(pixmap.width(), pixmap.height());
    this->setFixedSize(50, 50);
}

void Label::set_text_size(int size)
{
    QFont font = this->font();
    font.setPointSize(size);
    this->setFont(font);
}

void Label::set_icon_size(int width, int height)
{
    this->setFixedSize(width, height);
}

void Label::set_text_color(int red, int green, int blue)
{
    QPalette palette = this->palette();
    QColor customColor(red, green, blue);
    palette.setColor(QPalette::WindowText, customColor);
    this->setPalette(palette);
}