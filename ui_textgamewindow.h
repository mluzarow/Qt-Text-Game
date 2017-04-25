/********************************************************************************
** Form generated from reading UI file 'textgamewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTGAMEWINDOW_H
#define UI_TEXTGAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextGameWindow
{
public:
    QLineEdit *txtInput;
    QTextBrowser *txtOutput;

    void setupUi(QWidget *TextGameWindow)
    {
        if (TextGameWindow->objectName().isEmpty())
            TextGameWindow->setObjectName(QStringLiteral("TextGameWindow"));
        TextGameWindow->resize(400, 300);
        txtInput = new QLineEdit(TextGameWindow);
        txtInput->setObjectName(QStringLiteral("txtInput"));
        txtInput->setGeometry(QRect(10, 270, 381, 20));
        txtOutput = new QTextBrowser(TextGameWindow);
        txtOutput->setObjectName(QStringLiteral("txtOutput"));
        txtOutput->setGeometry(QRect(10, 10, 381, 261));

        retranslateUi(TextGameWindow);

        QMetaObject::connectSlotsByName(TextGameWindow);
    } // setupUi

    void retranslateUi(QWidget *TextGameWindow)
    {
        TextGameWindow->setWindowTitle(QApplication::translate("TextGameWindow", "TextGameWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TextGameWindow: public Ui_TextGameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTGAMEWINDOW_H
