#include "mace.h"

#include "engine.h"
#include "swing.h"

Mace::Mace(int damage) : Weapon{"mace", damage} {}

void Mace::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}