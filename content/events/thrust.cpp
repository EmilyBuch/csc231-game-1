#include "thrust.h"

#include "engine.h"
#include "hit.h"

Thrust::Thrust(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{10},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {
    sprite.shift.y -= sprite.size.y / 4;
    sprite.shift.x -= sprite.size.x / 2;

    if (direction == Vec{1, 0}) {  // right
        sprite.angle = 90;
    } else if (direction == Vec{-1, 0}) {  // left
        sprite.angle = -90;
    } else if (direction == Vec{0, -1}) {  // down
        sprite.angle = 180;
        this->direction = direction * -1;
    } else {  // up
        sprite.angle = 0;
        this->direction = direction * -1;
    }
}

void Thrust::execute(Engine&) {
    sprite.shift += direction / 3;
}

void Thrust::when_done(Engine& engine) {
    engine.events.add(Hit{defender, damage});
    sprite = original;
}
