#include "mace.h"

Mace::Mace(int damage) : Weapon{"mace", damage} {}

void Mace::use(Engine&, Actor&, Actor&) {}