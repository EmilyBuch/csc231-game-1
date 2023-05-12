#pragma once

#include "action.h"
#include "monstertype.h"

namespace Monsters {

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& m);
std::unique_ptr<Action> tired(Engine&, Monster&);

MonsterType goblin();
MonsterType skeleton();
MonsterType demon_tiny();
MonsterType heart_full();

}  // namespace Monsters
