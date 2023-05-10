#include "hammer.h"

#include "engine.h"
#include "hit.h"
#include "lightning.h"
#include "swing.h"

Hammer::Hammer(int damage) : Weapon{"hammer", damage} {}

void Hammer::use(Engine& engine, Actor& attacker, Actor& defender) {
    // Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Lightning{defender.get_position(), damage});
}

// Swing{sprite, direction, defender, damage}