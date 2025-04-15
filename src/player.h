#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QString>
#include <QMediaPlayer>
#include <QVideoWidget>

struct Player : QWidget 
{
    Player(QWidget* parent, const QString& video_path);

    void            set_geometry(int x, int y, int w, int h);

    QString         get_video_path()    const   { return this->video_path;      }
    QMediaPlayer*   get_video_player()  const   { return this->video_player;    }
    QVideoWidget*   get_video_widget()  const   { return this->video_widget;    }

private:
    QString         video_path;
    QMediaPlayer*   video_player;
    QVideoWidget*   video_widget;
};

#endif // PLAYER_H