
#include "calories.h"
#include "caloriesFunc.h"


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


void add_date_of_day(int& day, int& countUsers, Calories& calories){
    if(countUsers==0){
        return;}
    if (day == 30) {
        sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant");

        sf::Texture texture;
        if (!texture.loadFromFile("image7.png")) {
            return;
        }

        sf::Sprite sprite;
        sprite.setTexture(texture);

        sprite.setScale(
                static_cast<float>(window.getSize().x) / texture.getSize().x,
                static_cast<float>(window.getSize().y) / texture.getSize().y
        );

        sf::RectangleShape buttonDone(sf::Vector2f(100, 40));
        buttonDone.setPosition(window.getSize().x / 2 - buttonDone.getSize().x / 2,
                               window.getSize().y - buttonDone.getSize().y - 20);
        buttonDone.setFillColor(sf::Color(82, 82, 82, 200));

        sf::Font font;
        if (!font.loadFromFile("Arial_Black.ttf")) {
            return;
        }

        sf::Text textDone("Done", font, 20);
        textDone.setFillColor(sf::Color::White); // Белый текст
        textDone.setPosition(buttonDone.getPosition().x + 25, buttonDone.getPosition().y + 5);

        // Текст в середине экрана
        sf::Text textMessage("Congratulations! You have achieved a 30-day fitness marathon!", font, 32);
        textMessage.setFillColor(sf::Color::White);
        textMessage.setPosition(window.getSize().x / 2 - textMessage.getGlobalBounds().width / 2,
                                window.getSize().y / 2 - textMessage.getGlobalBounds().height / 2);


        sf::RectangleShape textBackground(sf::Vector2f(textMessage.getGlobalBounds().width + 20, textMessage.getGlobalBounds().height + 10));
        textBackground.setFillColor(sf::Color(0, 0, 0, 150));
        textBackground.setPosition(textMessage.getPosition().x - 10, textMessage.getPosition().y - 5);

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
            window.draw(textBackground);
            window.draw(textMessage);

            window.display();
        }
        return;
    }
    day++;
    std::vector<std::string> values;
    values = inputDate();
    std::vector<double>& spentCalories = calories.getSpentCalories();
    std::vector<double>& receivedCalories = calories.getReceivedCalories();
    spentCalories[day - 1] = std::stod(values[0]);
    receivedCalories[day - 1] = std::stod(values[1]);
    //recordedToFileForCalories(day, calories);
}



void deleteCalories(Calories & calories, int& day){
    day = 0;
    for(int i = 0; i < 30;i++) {
        calories.getReceivedCalories()[i] = 0;
        calories.getSpentCalories()[i] = 0;
    }
    recordedToFileForCalories(day);
}