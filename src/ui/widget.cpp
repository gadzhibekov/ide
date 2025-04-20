#include "widget.h"

#include "../../styles/styles.h"

#include <QFile>

Widget::Widget(QWidget* parent)
: QWidget(parent), parent(parent) {}

void Widget::set_geometry(int x, int y, int w, int h)
{
	this->setGeometry(x, y, w, h);
}

void Widget::set_style(const QString& css_file_path)
{
    QFile file(css_file_path);
	file.open(QIODevice::ReadOnly);
	QString data = file.readAll();
	file.close();

    this->setStyleSheet(data);
}