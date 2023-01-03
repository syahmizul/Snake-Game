#include "Snake.h"
#include "KeyboardBehavior.h"

sf::Clock Clock;
extern sf::CircleShape g_Food;

Snake::Snake() {
    float WindowCenter[2];
    WindowCenter[0] = WINDOW_WIDTH / 2;
    WindowCenter[1] = WINDOW_HEIGHT / 2;

    sf::CircleShape StartingPoint = sf::CircleShape(ShapeRadius);
    StartingPoint.setPosition(sf::Vector2f(WindowCenter[0], WindowCenter[1]));
    Body.push_back(StartingPoint);

    Behaviors[0] = new UpKeyBehavior(this);
    Behaviors[1] = new DownKeyBehavior(this);
    Behaviors[2] = new LeftKeyBehavior(this);
    Behaviors[3] = new RightKeyBehavior(this);
}

Snake::~Snake()
{
    for (int i = 0; i < 4; i++)
        delete Behaviors[i];
    delete[] Behaviors;
}

void Snake::Collision()
{
    if (Body[0].getGlobalBounds().intersects(g_Food.getGlobalBounds())) {
        g_Food.setPosition(sf::Vector2f(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT));
        switch (direction)
        {
            case(MoveDirection::UP):
            {
                sf::CircleShape NewHead(ShapeRadius);


                sf::Vector2f NewHeadPosition = Body[0].getPosition();
                NewHeadPosition.x += 0.0f;
                NewHeadPosition.y -= ShapeRadius;
                NewHead.setPosition(NewHeadPosition);

                Body.insert(Body.begin(), NewHead);
                break;
            }
            case(MoveDirection::DOWN):
            {
                sf::CircleShape NewHead(ShapeRadius);


                sf::Vector2f NewHeadPosition = Body[0].getPosition();
                NewHeadPosition.x += 0.0f;
                NewHeadPosition.y += ShapeRadius;
                NewHead.setPosition(NewHeadPosition);
                Body.insert(Body.begin(), NewHead);
                break;
            }
            case(MoveDirection::LEFT):
            {
                sf::CircleShape NewHead(ShapeRadius);


                sf::Vector2f NewHeadPosition = Body[0].getPosition();
                NewHeadPosition.x -= ShapeRadius;
                NewHeadPosition.y += 0.0f;
                NewHead.setPosition(NewHeadPosition);
                Body.insert(Body.begin(), NewHead);
                break;
            }
            case(MoveDirection::RIGHT):
            {
                sf::CircleShape NewHead(ShapeRadius);


                sf::Vector2f NewHeadPosition = Body[0].getPosition();
                NewHeadPosition.x += ShapeRadius;
                NewHeadPosition.y += 0.0f;
                NewHead.setPosition(NewHeadPosition);
                Body.insert(Body.begin(), NewHead);
                break;
            }
        }
    }
}

void Snake::Movement()
{

    switch (direction)
    {
        case(MoveDirection::UP):
        {
            sf::CircleShape NewHead(ShapeRadius);


            sf::Vector2f NewHeadPosition = Body[0].getPosition();
            NewHeadPosition.x += 0.0f;
            NewHeadPosition.y -= ShapeRadius;
            NewHead.setPosition(NewHeadPosition);

            Body.insert(Body.begin(), NewHead);
            Body.pop_back();
            break;
        }
        case(MoveDirection::DOWN):
        {
            sf::CircleShape NewHead(ShapeRadius);


            sf::Vector2f NewHeadPosition = Body[0].getPosition();
            NewHeadPosition.x += 0.0f;
            NewHeadPosition.y += ShapeRadius;
            NewHead.setPosition(NewHeadPosition);
            Body.insert(Body.begin(), NewHead);
            Body.pop_back();
            break;
        }
        case(MoveDirection::LEFT):
        {
            sf::CircleShape NewHead(ShapeRadius);


            sf::Vector2f NewHeadPosition = Body[0].getPosition();
            NewHeadPosition.x -= ShapeRadius;
            NewHeadPosition.y += 0.0f;
            NewHead.setPosition(NewHeadPosition);
            Body.insert(Body.begin(), NewHead);
            Body.pop_back();
            break;
        }
        case(MoveDirection::RIGHT):
        {
            sf::CircleShape NewHead(ShapeRadius);


            sf::Vector2f NewHeadPosition = Body[0].getPosition();
            NewHeadPosition.x += ShapeRadius;
            NewHeadPosition.y += 0.0f;
            NewHead.setPosition(NewHeadPosition);
            Body.insert(Body.begin(), NewHead);
            Body.pop_back();
            break;
        }
    }
}

void Snake::Input()
{
    for (KeyboardBehavior* behavior : Behaviors)
    {
        behavior->ShouldTick(behavior);
    }
}

void Snake::Draw(sf::RenderWindow* window)
{
    for (sf::CircleShape& shape : Body)
    {
        window->draw(shape);
    }
}

void Snake::Tick()
{
 
    Collision();
    Input();
    
    if (Clock.getElapsedTime().asMilliseconds() > 100)
    {
        Clock.restart();
        Movement();
    }

}