#pragma once

#include "weapon.h"

class Mace : public Weapon {
public:
    Mace(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};
