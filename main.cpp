#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    for (int i = 0; i < 10; ++i) {
        engine.create_monster(Monsters::goblin());
    }
    for (int i = 0; i < 10; ++i) {
        engine.create_monster(Monsters::demon_tiny());
    }
    for (int i = 0; i < 10; ++i) {
        engine.create_monster(Monsters::skeleton());
    }
    for (int i = 0; i < 15; ++i) {
        engine.create_monster(Monsters::heart_full());
    }

    engine.create_hero(Heros::dragon);
    engine.run();
}
