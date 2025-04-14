#include "label.h"

#include <QFont>
#include <QPixmap>

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

void Label::set_icon_size(int size)
{
    this->setFixedSize(size, size);
}