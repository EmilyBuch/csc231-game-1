#include "heal.h"

#include "actor.h"

constexpr int TEAM_HEART = 3;

Heal::Heal() {}

Result Heal::perform(Engine&) {
    int max = actor->max_health;

    // if the new health will be larger than the max health
    if (3 + actor->health > max) {
        // set the new health to max
        actor->health = max;
    }
    // if the new health will be less than max health
    else {
        // add 3 health points to the player's health
        actor->health += 3;
    }

    return success();
}