#pragma once
#include <SFML/Graphics.hpp>
#include "KeyboardBehavior.h"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

enum MoveDirection{
    UP ,
    DOWN,
    LEFT,
    RIGHT,
};

class Snake {

public:
    static constexpr float ShapeRadius = 10.0f;
    MoveDirection direction;
    std::vector<sf::CircleShape> Body;
    KeyboardBehavior* Behaviors[4];

    Snake();
    ~Snake();

    void Collision();
    void Movement();
    void Input();
    void Draw(sf::RenderWindow* window);

    void Tick();
};
