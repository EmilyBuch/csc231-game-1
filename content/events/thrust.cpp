#include "thrust.h"

#include "engine.h"
#include "hit.h"

Thrust::Thrust(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{5},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {}

void Thrust::execute(Engine&) {  // how does the weapon move over time?
    sprite.angle += -15;
    sprite.shift += direction * 3;
}

void Thrust::when_done(Engine& engine) {
    engine.events.add(Hit{defender, damage});
    sprite = original;
}
