#include <GLFW\glfw3.h>
#include <GL\glew.h>
#include <cmath>

double f(double x) {
    return sin(x);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(), "Function Plot");
    sf::Vector2u windowSize = window.getSize();
    double xRange = 10, yRange = 10;
    sf::Color funcColor = sf::Color::Color(0, 255, 0);
    sf::Color axisColor = sf::Color::Color(0, 0, 0);

    sf::Vertex line[2];

    double xCoef = windowSize.x / (2 * xRange), yCoef = windowSize.y / (2 * yRange);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::Resized) {
                windowSize = window.getSize();
                xCoef = windowSize.x / (2 * xRange);
                yCoef = windowSize.y / (2 * yRange);
            }
        }

        window.clear(sf::Color::White);

        line[0] = sf::Vertex(sf::Vector2f(0, windowSize.y / 2), axisColor);
        line[1] = sf::Vertex(sf::Vector2f(windowSize.x, windowSize.y / 2), axisColor);
        window.draw(line, 2, sf::Lines);
        line[0] = sf::Vertex(sf::Vector2f(windowSize.x / 2, 0), axisColor);
        line[0] = sf::Vertex(sf::Vector2f(windowSize.x / 2, windowSize.y), axisColor);
        window.draw(line, 2, sf::Lines);

        line[0] = sf::Vertex(sf::Vector2f(0, round((yRange - f(0)) * (windowSize.y / (2 * yRange)))), funcColor);
        for (size_t i = 1; i < windowSize.x; i++)
        {
            line[1] = sf::Vertex(sf::Vector2f(i, round((yRange - f(i / xCoef - xRange)) * (windowSize.y / (2 * yRange)))), funcColor);
            window.draw(line, 2, sf::Lines);
            line[0] = line[1];
        }

        window.display();
    }

    return 0;
}

//https://habr.com/ru/post/278977/