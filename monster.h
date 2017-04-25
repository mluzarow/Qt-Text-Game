#ifndef MONSTER_H
#define MONSTER_H

#include <QString>

class Monster {
public:
    Monster ();

    QString name;
    QString weapon;
    int hitpoints;
    int damage;
};

#endif // MONSTER_H
