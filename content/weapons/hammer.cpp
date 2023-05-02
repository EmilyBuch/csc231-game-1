#include "hammer.h"

#include "engine.h"
#include "hit.h"

Hammer::Hammer(int damage) : Weapon{"hammer", damage} {}

void Hammer::use(Engine& engine, Actor&, Actor& defender) {
    engine.events.add(Hit{defender, damage});
}
