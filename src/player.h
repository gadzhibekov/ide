#ifndef PLAYER_H
#define PLAYER_H

#include "ui/widget.h"

#include <QWidget>
#include <QString>
#include <QMediaPlayer>
#include <QVideoWidget>

struct Player : Widget 
{
    Player(QWidget* parent, const QString& video_path);

    void            set_geometry(int x, int y, int w, int h);

private slots:
    void            on_media_status_changed(QMediaPlayer::MediaStatus status);

private:
    QString         video_path;
    QMediaPlayer*   video_player;
    QVideoWidget*   video_widget;
};

#endif // PLAYER_H