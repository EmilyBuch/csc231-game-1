#pragma once

#include "actor.h"
#include "event.h"
#include "sprite.h"
#include "vec.h"

class Swing : public Event {
public:
    Swing(Sprite& sprite, Vec direction, Actor& defender, int damage);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite original;
    Actor& defender;
    int damage;
    double starting_angle, delta_angle;
};