#include "knife.h"

Knife::Knife(int damage) : Weapon{"knife", damage} {}

void Knife::use(Engine&, Actor&, Actor&) {}