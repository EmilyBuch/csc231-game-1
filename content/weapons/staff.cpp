#include "staff.h"

#include "engine.h"
#include "magic.h"

Staff::Staff(int damage) : Weapon{"staff_green", damage} {}

void Staff::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Magic{sprite, direction, defender, damage});
}
