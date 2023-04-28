#include "wander.h"

#include "actor.h"
#include "engine.h"
#include "move.h"
#include "randomness.h"
#include "rest.h"
#include "vec.h"

Result Wander::perform(Engine& engine) {
    Vec position = actor->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    shuffle(std::begin(neighbors), std::end(neighbors));
    // for each, find not wall and non-occupied tile
    for (Vec neighbor : neighbors) {
        Tile& tile = engine.dungeon.tiles(neighbor);
        if (!tile.is_wall() && !tile.actor) {
            Vec direction = neighbor - position;
            return alternative(Move{direction});
        }
    }
    return alternative(Rest{});
}