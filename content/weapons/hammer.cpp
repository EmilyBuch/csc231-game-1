#include "hammer.h"

Hammer::Hammer(int damage) : Weapon{"hammer", damage} {}

void Hammer::use(Engine&, Actor&, Actor&) {}
