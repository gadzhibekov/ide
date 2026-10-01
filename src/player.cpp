#include "player.h"

#include <QVBoxLayout>
#include <QObject>
#include <QFileInfo>
#include <QUrl>
#include <QAudioOutput>

Player::Player(QWidget* parent, const QString& video_path) 
    : Widget(parent),
      video_path(video_path),
      video_player(new QMediaPlayer(this)),
      video_widget(new QVideoWidget(this))
{
    video_player->setVideoOutput(video_widget);

    QAudioOutput* audio_output = new QAudioOutput(this);
    video_player->setAudioOutput(audio_output);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(video_widget);
    setLayout(layout);

    video_player->setSource(QUrl::fromLocalFile(QFileInfo(video_path).absoluteFilePath()));
    audio_output->setVolume(0.0);

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