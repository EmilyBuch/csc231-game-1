#include "swing.h"

#include <cmath>

#include "engine.h"
#include "hit.h"

constexpr int duration = 10;

Swing::Swing(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{duration},
      sprite{sprite},
      original{sprite},
      defender{defender},
      damage{damage} {
    if (direction == Vec{1, 0}) {  // right
        starting_angle = 0;
        delta_angle = 135.0 / (duration - 1);
    } else if (direction == Vec{-1, 0}) {  // left
        starting_angle = 0;
        delta_angle = -135.0 / (duration - 1);
    } else if (direction == Vec{0, -1}) {  // down
        sprite.shift.x = 0;
        double sign = std::copysign(1.0, starting_angle);
        // 15 -> 1 and -15 -> -1
        starting_angle = 135 * sign;
        delta_angle = 180.0 / (duration - 1) * sign;
    } else {  // up
        double sign = std::copysign(1.0, starting_angle);
        // 15 -> 1 and -15 -> -1
        starting_angle = -75 * sign;
        delta_angle = 180.0 / (duration - 1) * sign;
        sprite.shift.y -= 12;
    }
}

void Swing::execute(Engine&) {
    sprite.angle = starting_angle + delta_angle * frame_count;
}

void Swing::when_done(Engine& engine) {
    engine.events.add(Hit{defender, damage});
    sprite = original;
}
