#include "mace.h"

#include "engine.h"
#include "hit.h"

Mace::Mace(int damage) : Weapon{"mace", damage} {}

void Mace::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}