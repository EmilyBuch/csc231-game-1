#include "magic.h"

#include "engine.h"
#include "hit.h"
#include "lightning.h"

Magic::Magic(Sprite& sprite, Vec direction, Actor& defender, int damage)
    : Event{5},
      sprite{sprite},
      original{sprite},
      direction{direction},
      defender{defender},
      damage{damage} {
    sprite.angle = 0;
    this->direction = direction * -1;
}

void Magic::execute(Engine&) {
    sprite.shift.y -= 1;
}

void Magic::when_done(Engine& engine) {
    engine.events.add(Lightning{defender.get_position(), damage});
    sprite = original;
}
