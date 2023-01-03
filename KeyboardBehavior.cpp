#include "KeyboardBehavior.h"
#include "Snake.h"
void KeyboardBehavior::ShouldTick(KeyboardBehavior* behavior)
{
    if (sf::Keyboard::isKeyPressed(behavior->key))
    {
        behavior->Tick();
    }
}
UpKeyBehavior::UpKeyBehavior(Snake* snake)
{
    this->snake = snake;
    key = sf::Keyboard::Up;
}

void UpKeyBehavior::Tick()
{
    snake->direction = MoveDirection::UP;
}

DownKeyBehavior::DownKeyBehavior(Snake* snake)
{
    this->snake = snake;
    key = sf::Keyboard::Down;
}
void DownKeyBehavior::Tick()
{
    snake->direction = MoveDirection::DOWN;
}

LeftKeyBehavior::LeftKeyBehavior(Snake* snake)
{
    this->snake = snake;
    key = sf::Keyboard::Left;
}
void LeftKeyBehavior::Tick()
{
    snake->direction = MoveDirection::LEFT;
}

RightKeyBehavior::RightKeyBehavior(Snake* snake)
{
    this->snake = snake;
    key = sf::Keyboard::Right;
}
void RightKeyBehavior::Tick()
{
    snake->direction = MoveDirection::RIGHT;
}