#pragma once

#include "herotype.h"
#include "move.h"
#include "none.h"

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
     }}  // s -> down
};

constexpr int default_speed{8};
const HeroType nobody{"dragon", default_speed, 1, std::make_shared<None>(),
                      key_bindings};

}  // namespace Heros
