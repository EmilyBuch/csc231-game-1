#include "lightning.h"

#include "engine.h"
#include "hit.h"

Lightning::Lightning(Vec position, int damage)
    : position{position}, damage{damage} {}

void Lightning::execute(Engine& engine) {
    if (frame_count == 0) {
        sprite = engine.graphics.get_animated_sprite("lightning", 2);
        sprite.shift(Vec{0, 15});
        number_of_frames = sprite.number_of_frames() * 2;
    }

    // draw current animation frame
    engine.camera.add_overlay(position, sprite.get_sprite());
    if (frame_count % 2 == 0) {
        sprite.update();  // moves to the next frame
    }
}

void Lightning::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.actor) {
        engine.events.add(Hit{*tile.actor, damage});
    }
}
