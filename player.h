#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "monster.h"

enum PlayerClass {
    warrior, wizard
};

class Player {
public:
    // Constructor
    Player ();

    PlayerClass playerClass;    // Player's class
    QString nameFirst;  // Player's first name
    QString nameLast;   // Player's last name
    QString spell;      // Player's spell I guess? I'm not sure what this really means
    QString weapon;     // Player's weapon
    QString armor;      // Player's armor
    Monster boss;       // Player's chosen boss monster
    Monster monster;    // Current monster we are fighting
    int hitpoints;      // Hitpoints
    int xhp;
    int potion;
    int experience;     // Experience
    int lxp;
    int mxp;
    int dr;
    int mhp;
    int md;
    int damageAttack;   // Attack damage
    int damageSpell;    // Spell damage
    int mspl;
    int level;          // Current level
};

#endif // PLAYER_H
