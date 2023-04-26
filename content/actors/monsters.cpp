#include "monsters.h"

#include "none.h"
#include "rest.h"

namespace Monsters {

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& m) {
    return std::make_unique<Rest>();
}

constexpr int default_speed{8};

MonsterType goblin() {
    int health = 2;
    return {"goblin", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

MonsterType skeleton() {
    int health = 2;
    return {"skeleton", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

MonsterType demon_tiny() {
    int health = 2;
    return {"demon_tiny", default_speed, health, std::make_shared<None>(),
            default_behavior};
}

}  // namespace Monsters
