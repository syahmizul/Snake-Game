#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Snake;

class KeyboardBehavior {
public:
    sf::Keyboard::Key key;
    Snake* snake;

    KeyboardBehavior(){}
    virtual ~KeyboardBehavior() {}

    virtual void ShouldTick(KeyboardBehavior* behavior);
    virtual void Tick() {};
};

class UpKeyBehavior : public KeyboardBehavior {
public:
    UpKeyBehavior(Snake* snake);
    virtual ~UpKeyBehavior() {}

    void Tick();
    
};

struct DownKeyBehavior : public KeyboardBehavior {
public:
    DownKeyBehavior(Snake* snake);
    virtual ~DownKeyBehavior() {}

    void Tick();
    
};

struct LeftKeyBehavior : public KeyboardBehavior {
public:
    LeftKeyBehavior(Snake* snake);
    virtual ~LeftKeyBehavior() {}
    void Tick();
    
};

struct RightKeyBehavior : public KeyboardBehavior {
public:
    RightKeyBehavior(Snake* snake);
    virtual ~RightKeyBehavior() {}
    void Tick();
    
};