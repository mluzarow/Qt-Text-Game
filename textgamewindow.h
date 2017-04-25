#ifndef TEXTGAMEWINDOW_H
#define TEXTGAMEWINDOW_H

#include <QWidget>
#include "player.h"

namespace Ui {
    class TextGameWindow;
}

class TextGameWindow : public QWidget {
    Q_OBJECT

public:
    // Class stuff
    explicit TextGameWindow (QWidget *parent = 0);
    ~TextGameWindow ();

    // Variables
    int gameStage;
    Player player;

    // Functions
    void parseInput (QString);

private slots:
    void on_txtInput_returnPressed();

private:
    Ui :: TextGameWindow *ui;
};

#endif // TEXTGAMEWINDOW_H
