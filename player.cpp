#include "player.h"
#include "textgamewindow.h"

Player :: Player () {
    level = 1;
    xhp = 12;
    dr = 1;
    hitpoints = 12;
    experience = 0;
    potion = 1;
    lxp = 100;
    damageAttack = 7;
    damageSpell = level * 4;

    armor = "shield";
    weapon = "sword";
    spell = "ATTACK";
}
