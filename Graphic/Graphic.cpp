#include "Graphic.h"

void window() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fitness Assistant");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(0, 255, 80, 0));

        window.display();
    }
}