#ifndef WELCOME
#define WELCOME

#define FLOWERS_ANIM_PATH   "../res/flowers_anim.mp4"
#define LEKI_FLAG_PATH      "../res/leki_flag.jpg"
#define RU_FLAG_PATH        "../res/ru_flag.png"
#define US_FLAG_PATH        "../res/us_flag.png"
#define TG_ICON_PATH        "../res/tg.png"
#define GITHUB_ICON_PATH    "../res/github.png"
#define GITHUB_LINK         "https://github.com/gadzhibekov/ide"
#define TG_LINK             "https://t.me/gadzhibekov_05"

#include "ui/button.h"
#include "ui/label.h"
#include "ui/dialog_window.h"
#include "player.h"
#include "panel_tools.h"
#include "panel.h"

#include <QWidget>
#include <QString>
#include <QResizeEvent>

struct PanelTools;

struct Welcome : QWidget
{
    Welcome(QWidget* parent, int width, int height);

    void            set_geometry(int x, int y, int w, int h);
    void            set_dialog_window_ptr(DialogWindow* dialog_window);
    void            set_panel_tools_ptr(PanelTools* panel_tools);
    void            set_panel_ptr(Panel* panel);

    Label*          get_welcome_text_1()        const   { return this->welcome_text_1;      }
    Label*          get_welcome_text_2()        const   { return this->welcome_text_2;      }
    Button*         get_open_dir_prototype()    const   { return this->open_dir_prototype;  }
    Button*         get_translate_to_leki()     const   { return this->translate_to_leki;   }
    Button*         get_translate_to_ru()       const   { return this->translate_to_ru;     }
    Button*         get_translate_to_en()       const   { return this->translate_to_en;     }
    Button*         get_github_link()           const   { return this->github_link;         }
    Button*         get_tg_link()               const   { return this->tg_link;             }
    Player*         get_player()                const   { return this->player;              }

protected:
    void            resizeEvent(QResizeEvent* event)   override;

private:
    Player*         player;
    DialogWindow*   dialog_window;
    PanelTools*     panel_tools;
    Panel*          panel;
    Label*          welcome_text_1;
    Label*          welcome_text_2;
    Button*         open_dir_prototype;
    Button*         translate_to_leki;
    Button*         translate_to_ru;
    Button*         translate_to_en;
    Button*         github_link;
    Button*         tg_link;

    void            translate_to_leki_slot();
    void            translate_to_ru_slot();
    void            translate_to_en_slot();
    void            open_dir_prototype_slot();
    void            open_github_link_slot();
    void            open_tg_link_slot();
};

#endif // WELCOME