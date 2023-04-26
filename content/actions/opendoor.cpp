#include "opendoor.h"

#include "engine.h"
#include "move.h"
#include "updatefov.h"

OpenDoor::OpenDoor(Vec position) : position{position} {}

Result OpenDoor::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    Door& door = engine.dungeon.doors.at(position);
    if (tile.is_door()) {
        door.open();
        tile.walkable = true;
    } else {
    }

    engine.events.add(UpdateFOV{});
    return success();
}