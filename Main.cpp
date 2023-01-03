#include <SFML/Graphics.hpp>

#include "Snake.h"
#include <random>

sf::CircleShape g_Food;

int main()
{
    srand((unsigned)time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Snake Game");
    Snake snake;
    g_Food.setRadius(Snake::ShapeRadius);
    g_Food.setPosition(sf::Vector2f(rand()% WINDOW_WIDTH, rand() % WINDOW_HEIGHT));

    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        snake.Tick();
        snake.Draw(&window);
        window.draw(g_Food);

        window.display();
    }

    return 0;
}