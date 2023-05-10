#pragma once

#include "action.h"

class Heal : public Action {
public:
    Heal();
    Result perform(Engine& engine) override;
};