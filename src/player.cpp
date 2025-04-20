#include "player.h"

#include <QVBoxLayout>
#include <QObject>
#include <QFileInfo>
#include <QUrl>

Player::Player(QWidget* parent, const QString& video_path) 
    : Widget(parent),
      video_path(video_path),
      video_player(new QMediaPlayer(this)),
      video_widget(new QVideoWidget(this))
{
    video_player->setVideoOutput(video_widget);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(video_widget);
    setLayout(layout);

    video_player->setMedia(QUrl::fromLocalFile(QFileInfo(video_path).absoluteFilePath()));
    video_player->setVolume(0);

    QObject::connect(video_player, &QMediaPlayer::mediaStatusChanged, this, &Player::on_media_status_changed);

    video_player->play();
}


void Player::on_media_status_changed(QMediaPlayer::MediaStatus status) 
{
    if (status == QMediaPlayer::EndOfMedia) 
    {
        video_player->setPosition(0);
        video_player->play();
    }
}

void Player::set_geometry(int x, int y, int w, int h)
{
    this->setGeometry(x, y, w, h);
}