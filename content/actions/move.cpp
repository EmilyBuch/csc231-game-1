#include "move.h"

#include <iostream>

#include "actor.h"
#include "attack.h"
#include "engine.h"
#include "heal.h"
#include "opendoor.h"
#include "rest.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position() + direction;
    actor->change_direction(direction);

    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_wall()) {
        return failure();
    }

    Actor* defender = engine.dungeon.tiles(position).actor;
    if (defender != nullptr) {
        if (defender->team == 3) {
            actor->move_to(position);
            // defender --health;
            return alternative(Heal{});
        } else if (actor->team == defender->team) {
            return alternative(Rest{});
        } else {
            return alternative(Attack{*defender});
        }
    }

    if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(position);
        if (!door.is_open()) {
            return alternative(OpenDoor{position});
        }
    }

    actor->move_to(position);

    return success();
}
