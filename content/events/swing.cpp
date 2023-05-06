#include "swing.h"

#include "engine.h"
#include "hit.h"

Swing::Swing(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{5},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {}

void Swing::execute(Engine&) {
    sprite.angle -= -15;
    sprite.shift += direction * 5;
    sprite.angle += 90;
}

void Swing::when_done(Engine& engine) {
    engine.events.add(Hit{defender, damage});
    sprite = original;
}
