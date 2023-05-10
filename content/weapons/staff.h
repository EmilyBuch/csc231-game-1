#pragma once

#include "weapon.h"

class Staff : public Weapon {
public:
    Staff(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};
