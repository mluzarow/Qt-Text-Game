#include "textgamewindow.h"
#include "ui_textgamewindow.h"

// Constructor
TextGameWindow :: TextGameWindow (QWidget *parent) : QWidget (parent), ui (new Ui :: TextGameWindow) {
    ui->setupUi (this);

    ui->txtOutput->insertPlainText("Welcome to Adventure v 1.993, the final version!!!!!\n"
                            "Now even  more efficient coding "
                            " And even a story line with improved, expirerence system,"
                            " charcter devolpment, with 5 items!! \n Rated E for everyone \n"
                            "Please input your first name \n");
}
// Destructor
TextGameWindow :: ~TextGameWindow () {
    delete ui;
}
// Events - Return key pressed
void TextGameWindow :: on_txtInput_returnPressed () {
    // Append output box with the contents of input box
    ui->txtOutput->insertPlainText("\n   >>" + ui->txtInput->text () + "\n\n");
    gameStage++;
    parseInput (ui->txtInput->text ());
    ui->txtInput->setText ("");
}

void TextGameWindow :: parseInput (QString s) {
    // Enter first name
    if (gameStage == 1) {
        player.nameFirst = s;

        ui->txtOutput->insertPlainText ("And now your last name. \n");

    // Enter last name
    } else if (gameStage == 2) {
        player.nameLast = s;

        ui->txtOutput->insertPlainText (" And now your charcter class: pick from:"
                                        " \n wizard or warrior \n");

    // Choose a class
    } else if (gameStage == 3) {
        if (s.toUpper () == "WIZARD") {
            player.playerClass = wizard;
        } else if (s.toUpper () == "WARRIOR") {
            player.playerClass = warrior;
        } else {
            gameStage--;
            ui->txtOutput->insertPlainText ("Error: Invalid input.\n");
        }
        ui->txtOutput->insertPlainText (QStringLiteral ("\"%1 %2, mighty %3"
                ", you have been chosen to defeat the vile monsters that plauge"
                " our land. Only you have the power to defeat these vile beasts.   \n"
                "Chose your nemisis %1. Will you go after the lich, undead spirt of"
                " a mighty wizard who has chosen our hapless village for his next conquest."
                " Or will you go after the dragon who eats our townsfolk with"
                " his vile reptillian minions. Or will you go after the balrog"
                " and his legion of demons, here to destroy the world itself. \n"
                " Chose wisely, for though you are the promised one, you are"
                " but mortal \" \n "
                "pick an archvillain \n"
                "D for dragon, L for lich, B for Balrog \n").arg (
                                            player.nameFirst,
                                            player.nameLast,
                                            (player.playerClass == wizard ? "wizard" : "warrior")));

    // Choose a boss
    } else if (gameStage == 4) {
        if (s.toUpper() == "D") {
            //player.boss = Monster ();
        } else if (s.toUpper() == "L") {
            //player.boss = Monster ();
        } else if (s.toUpper() == "B") {
            //player.boss = Monster ();
        } else {
            gameStage--;
            ui->txtOutput->insertPlainText ("Error: Invalid input.\n");
        }

        ui->txtOutput->insertPlainText (QStringLiteral (
                "An excellent choice, here is your trusty %1; use it wisely"
                " for it is the finest weapen in the village. Here is the mighty "
                "%2 the blacksmith made last week to defend you."
                "\"Now I will use my powers of teleportation to bring you to the lair"
                " of this evil creature, hold on, for magic is dangerous"
                " remember, I have taught thee several powerful spells... \""
                "\"Farewell \n"
                "you stand in a tunnel looking at a large black door. \n"
                "Your stats are: \n hp: %3 \n weapon: "
                "%1 \n damage with weapon: %4"
                " \n armor: %2 \n spell: %5"
                " \n spell damage: %6\n level: %7"
                " \nYou hear a noise...\nIf you draw your "
                "%1 and crouch press S, if you try to find the source press F \n").arg (
                                            player.weapon,
                                            player.armor,
                                            QString::number (player.hitpoints),
                                            QString::number (player.damageAttack),
                                            player.spell,
                                            QString::number (player.damageSpell),
                                            QString::number (player.level)));
    // Finding the source of the noise
    } else if (gameStage == 5) {
        // Find the source
        if (s.toUpper() == "F") {
            if (player.boss.name == "Lich") {
                ui->txtOutput->insertPlainText("A lich comes out and casts FINGER OF DEATH. You are killed. \n");
            } else if (player.boss.name == "Black Dragon") {
                ui->txtOutput->insertPlainText("A Black Dragon rears up and spits corrosive acid. You die. \n");
            } else if (player.boss.name == "Balrog") {
                ui->txtOutput->insertPlainText("A Balrog sneaks up behind you and chops you in half with its flaming sword. You die. \n");
            }
            ui->txtOutput->insertPlainText("You are such a loser for dying \n");
            //ui->txtInput->readOnly (true);

        // Crouch
        } else if (s.toUpper() == "S") {
            ui->txtOutput->insertPlainText(QStringLiteral (
                                               "You draw your trusty %1 and shield and see a %2!! \n").arg (
                                               player.weapon,
                                               player.monster.name));

            ui->txtOutput->insertPlainText(QStringLiteral (
                            "If you want to attack the %1 with your %2, press S."
                            "If you want to try to destroy it with a %3 spell, press A.\n").arg (
                                                   player.monster.name,
                                                   player.weapon,
                                                   player.spell));
        }
    // Combat result loop
    } else if (gameStage == 6) {
        if (s.toUpper() == "S") {
            ui->txtOutput->insertPlainText(QStringLiteral (
                                               "You swing your %1 at the %2 and you hit... \n").arg (
                                               player.weapon,
                                               player.monster.name));
            player.monster.hitpoints -= player.damageAttack;
        } else if (s.toUpper() == "A") {
            ui->txtOutput->insertPlainText(QStringLiteral (
                                               "You release pent up magic energy in a %1 spell...\n").arg (
                                               player.spell));
            player.monster.hitpoints -= player.damageSpell;
        }
        if (player.monster.hitpoints > 0) {
            ui->txtOutput->insertPlainText(QStringLiteral (
                                               "The %1 hits you with its %2... \n").arg (
                                               player.monster.name,
                                               player.monster.weapon));

            if (player.dr <= player.monster.damage) {
                player.hitpoints = player.hitpoints - (player.monster.damage - player.dr);
            }

            ui->txtOutput->insertPlainText(QStringLiteral (
                                               "You have %1 hitpoints remaining.\n").arg (
                                               player.hitpoints));

            if (player.hitpoints <= 0) {
                   ui->txtOutput->insertPlainText ("You are dead. You are such a loser for dying. \n");
                   //ui->txtInput->readOnly (true);
            } else {
                ui->txtOutput->insertPlainText(QStringLiteral (
                                "If you want to attack the %1 with your %2, press S."
                                "If you want to try to destroy it with a %3 spell, press A.\n").arg (
                                                       player.monster.name,
                                                       player.weapon,
                                                       player.spell));
                gameStage--;
            }
         }
    }
}
