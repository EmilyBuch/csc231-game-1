#pragma once

#include "action.h"
#include "monstertype.h"

namespace Monsters {

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& m);

MonsterType goblin();
MonsterType skeleton();
MonsterType demon_tiny();

}  // namespace Monsters
