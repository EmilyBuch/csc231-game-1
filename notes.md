

## Actions
```C++
\\ override this
Result Action::perform(Engine& engine) = 0;
```
**Remember** Actions contain a shared_ptr<Actor> called *actor*

### Rest
```C++
class Rest : public Action {
public:
    Result perform (Engine& engine) override;
};
```

## Result
```C++
struct Result {
    bool succeeded{false};
    // allows chaining of actions
    shared_ptr<Action>
}
```
return these from Action::perform()
- success() - Action worked, finished with turn
- failure() - Action didn't work, try a different action
- alternative(do_this_instead) - cannot perform an action, do a different action instead

Monsters
    for each neighboring tile:
        if tile is walkable and has no actor:
            return alternative(Move{})
        else
            return alternative(Rest{})

## Moving
-Vec
    (x, y) tile loation.
    (0, 0) is bottom-left
    operator + and - goes up and right or down and left
    new_position = position {x, y} + direction {0, 1}
-Actor
    public member function
-Tiles
    Tile& tile = engine.dungeon.tiles(position)
-Tile
    is_wall(), bool walkable, Actor* actor
-Keybinding
    in struct HeroType --> std::unordered_mapp<std::string, Reaction> key_bindings;

```C++
std::unordered_map<std::string, int> contacts = {
    {"name", value},
    {"name", value},
}
using Reaction = std::function<std::unique_ptr<Action>()>

std::function<int(int,int)> func_onj = add;
//  return type^  ^args^
or = [](intx, int y) {return x + y;}
// [] is a function
```


## Actor
```C++
void change_direction(Vec);
void move_to(Vec);
Vec get_position();
```

## Door
Move to the door position (tile)
find out that it is a door
return alternative(open_door(vec{position}))

```C++
OpenDoor(Vec position)
    // can get tile and door from position
OpenDoor(Door, Tile) //< too much info. Not its job
```
Change the lighting after opening the door

Closing - search the surrounding tiles (4)

## Weapons
```C++
Weapons::use (Engine& engine, Actor& attacker, Actor& defender)
```
Weapons can be for a selection of spaces based on the actor
Weapons need a damage amount
Need animation(s)
Allows Weapons to vary (including hurting yourself, game ending, teleporting)

## Attack
Hit event -> the rest of the game processes
```C++
defender.take_damage(amount)
```
This amount is for each Weapon


## Angles
direction angle = atan2(y, x) \\atan2 = arctan()
sprite angle = -1 * (direction angle) + 90

## Ideas for Final
- Healing with randomly spawning hearts
- figure out how to do animation

## Things to do to complete the game
- change hero's health (lower)
- mess with the spawn rate of monsters
- maybe add a few large monsters
- add the final addition

modify engine and add a heart "monster"
    default behavior Rest
    default weapon None
in move, check team. If heart, action heal
