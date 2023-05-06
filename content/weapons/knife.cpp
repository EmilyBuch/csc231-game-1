#include "knife.h"

#include "engine.h"
#include "thrust.h"

Knife::Knife(int damage) : Weapon{"knife", damage} {}

void Knife::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Thrust{sprite, direction, defender, damage});
}