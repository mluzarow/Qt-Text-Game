/****************************************************************************
 ** Main entry point
 **
 ** Some sorta license
 **
 ** OK bye
****************************************************************************/
#include <QApplication>
#include "textgamewindow.h"

int main (int argc, char *argv []) {
    // The GUI system
    QApplication app (argc, argv);
    // The game window
    TextGameWindow window;
    window.show ();

    return app.exec ();
}
