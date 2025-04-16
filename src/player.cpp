#include "player.h"

Player::Player(QWidget* parent, const QString& video_path) : QWidget(parent), video_path(video_path)
{
    this->setStyleSheet("background-color: grey;");
}

void Player::set_geometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);
}