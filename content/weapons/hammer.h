#pragma once

#include "weapon.h"

class Hammer : public Weapon {
public:
    Hammer(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;

private:
};