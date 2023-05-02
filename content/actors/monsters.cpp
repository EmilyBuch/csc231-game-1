#include "monsters.h"

#include "engine.h"
#include "hammer.h"
#include "knife.h"
#include "mace.h"
#include "monster.h"
#include "move.h"
#include "none.h"
#include "randomness.h"
#include "rest.h"
#include "wander.h"

namespace Monsters {

std::unique_ptr<Action> default_behavior(Engine& engine, Monster& m) {
    if (m.is_visible() && engine.hero) {
        std::vector<Vec> path = engine.dungeon.calculate_path(
            m.get_position(), engine.hero->get_position());
        if (path.size() > 1) {
            Vec direction = path.at(1) - path.at(0);
            return std::make_unique<Move>(direction);
        }
    }

    if (probability(33)) {
        return std::make_unique<Wander>();
    } else {
        return std::make_unique<Rest>();
    }
}

constexpr int default_speed{8};

MonsterType goblin() {
    int health = 2;
    return {"goblin", default_speed, health, std::make_shared<Knife>(1),
            default_behavior};
}

MonsterType skeleton() {
    int health = 2;
    return {"skeleton", default_speed, health, std::make_shared<Mace>(2),
            default_behavior};
}

MonsterType demon_tiny() {
    int health = 2;
    return {"demon_tiny", default_speed, health, std::make_shared<Knife>(1),
            default_behavior};
}

}  // namespace Monsters
