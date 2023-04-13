

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
    Vec
        (x, y) tile loation.
        (0, 0) is bottom-left
        operator + and - goes up and right or down and left
    Actor
        public member function
    Tiles
        Tile& tile = engine.dungeon.tiles(position)
    Tile
        is_wall(), bool walkable, Actor* actor