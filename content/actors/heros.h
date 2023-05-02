#pragma once

#include "closedoor.h"
#include "hammer.h"
#include "herotype.h"
#include "hit.h"
#include "move.h"
#include "none.h"
#include "rest.h"

namespace Heros {

// Reaction = std::function<std::unique_ptr<Action>()>
const std::unordered_map<std::string, Reaction> key_bindings = {
    {"A",
     []() {
         return std::make_unique<Move>(Vec{-1, 0});
     }},  // a -> left

    {"D",
     []() {
         return std::make_unique<Move>(Vec{1, 0});
     }},  // d -> right

    {"W",
     []() {
         return std::make_unique<Move>(Vec{0, 1});
     }},  // w -> up

    {"S",
     []() {
         return std::make_unique<Move>(Vec{0, -1});
     }},                                               // s -> down
    {"R", []() { return std::make_unique<Rest>(); }},  // r -> rest
    {"Space", []() { return std::make_unique<CloseDoor>(); }},
    // {"Left", []() { return std::make_unique<Hit>(); }},
    // {"Right", []() {return std::make_unique<Hit>();}},
    // {"Up", []() {return std::make_unique<Hit>();}},
    // {"Down", []() {return std::make_unique<Hit>():}},
};

constexpr int default_speed{8};
const HeroType dragon{"dragon", default_speed, 100, std::make_shared<Hammer>(8),
                      key_bindings};

}  // namespace Heros