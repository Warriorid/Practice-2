
#include "calories.h"


void statistic() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant");

    sf::Texture texture;
    if (!texture.loadFromFile("image6.png")) {
        return;
    }

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sprite.setScale(
            static_cast<float>(window.getSize().x) / texture.getSize().x,
            static_cast<float>(window.getSize().y) / texture.getSize().y
    );

    // Кнопка "Done"
    sf::RectangleShape buttonDone(sf::Vector2f(100, 40));
    buttonDone.setPosition(window.getSize().x / 2 - buttonDone.getSize().x / 2,
                           window.getSize().y - buttonDone.getSize().y - 20);
    buttonDone.setFillColor(sf::Color(82, 82, 82, 200)); // Серый цвет

    sf::Font font;
    if (!font.loadFromFile("Arial_Black.ttf")) {
        return;
    }

    sf::Text textDone("Done", font, 20);
    textDone.setFillColor(sf::Color::White); // Белый текст
    textDone.setPosition(buttonDone.getPosition().x + 25, buttonDone.getPosition().y + 5); // Центрируем текст на кнопке

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (buttonDone.getGlobalBounds().contains(mousePos)) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color::White);

        window.draw(sprite);
        window.draw(buttonDone);
        window.draw(textDone);

        window.display();
    }
}


void add_date_of_day(int& day){
    inputDate();
}