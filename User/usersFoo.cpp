
#include "users.h"
#include "../Tool/tools.h"

void addUser(User & man, int& countUsers){
    if (countUsers==1){
            sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant");

            sf::Font font;
            if (!font.loadFromFile("Arial_Black.ttf")) {
                return;
            }
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("image4.png")) {
            return;
        }
        sf::Sprite backgroundSprite;
        backgroundSprite.setTexture(backgroundTexture);
            sf::Text text("Sorry, but the user has already been added, delete or edit the current one", font, 30);
            text.setFillColor(sf::Color::White);
            text.setPosition(window.getSize().x / 2.f - text.getGlobalBounds().width / 2.f, window.getSize().y / 2.f - text.getGlobalBounds().height / 2.f);

            // Кнопка "Done"
            sf::RectangleShape button(sf::Vector2f(100.f, 40.f));
            button.setFillColor(sf::Color(82, 82, 82, 200));
            button.setPosition(window.getSize().x / 2.f - button.getSize().x / 2.f, window.getSize().y / 2.f + text.getGlobalBounds().height + 20.f);

            sf::Text buttonText("Done", font, 20);
            buttonText.setFillColor(sf::Color::White);
            buttonText.setPosition(button.getPosition().x + button.getSize().x / 2.f - buttonText.getGlobalBounds().width / 2.f,
                                   button.getPosition().y + button.getSize().y / 2.f - buttonText.getGlobalBounds().height / 2.f);

            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                        if (button.getGlobalBounds().contains(mousePos)) {
                            window.close();
                        }
                    }
                }

                window.clear(sf::Color::White);
                window.draw(backgroundSprite);
                window.draw(text);
                window.draw(button);
                window.draw(buttonText);
                window.display();
            }
            return;
        }
    std::vector<std::string> values;
    values = getDate();
    man.setName(values[0]);
    man.setAge(std::stoi(values[1]));
    man.setHeight(std::stoi(values[2]));
    man.setWeight(std::stod(values[3]));
    countUsers++;
    recordedToFile(man, countUsers);

}

void Delete(User & man, int& countUsers){
    countUsers = 0;
    man.setName("-");
    man.setAge(0);
    man.setHeight(0);
    man.setWeight(0.0);
    recordedToFile(man, countUsers);
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant");

    sf::Font font;
    if (!font.loadFromFile("Arial_Black.ttf")) {
        return;
    }
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("image4.png")) {
        return;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    sf::Text text("The user has been successfully deleted", font, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x / 2.f - text.getGlobalBounds().width / 2.f, window.getSize().y / 2.f - text.getGlobalBounds().height / 2.f);

    // Кнопка "Done"
    sf::RectangleShape button(sf::Vector2f(100.f, 40.f));
    button.setFillColor(sf::Color(82, 82, 82, 200));
    button.setPosition(window.getSize().x / 2.f - button.getSize().x / 2.f, window.getSize().y / 2.f + text.getGlobalBounds().height + 20.f);

    sf::Text buttonText("Done", font, 20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(button.getPosition().x + button.getSize().x / 2.f - buttonText.getGlobalBounds().width / 2.f,
                           button.getPosition().y + button.getSize().y / 2.f - buttonText.getGlobalBounds().height / 2.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (button.getGlobalBounds().contains(mousePos)) {
                    window.close();
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(backgroundSprite);
        window.draw(text);
        window.draw(button);
        window.draw(buttonText);
        window.display();
    }
}

void DisplayUser(User & man, int& countUsers) {

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant");

    sf::Font font;
    if (!font.loadFromFile("Arial_Black.ttf")) {
        return;
    }

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("image3.png")) {
        return;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Кнопка "Done"
    sf::RectangleShape buttonDone(sf::Vector2f(100, 40));
    buttonDone.setPosition(window.getSize().x / 2 - buttonDone.getSize().x / 2, window.getSize().y - buttonDone.getSize().y - 400);
    buttonDone.setFillColor(sf::Color(82, 82, 82, 200)); // Серый цвет

    sf::Text textDone("Done", font, 20);
    textDone.setFillColor(sf::Color::White); // Белый текст
    textDone.setPosition(buttonDone.getPosition().x + 25, buttonDone.getPosition().y + 5); // Центрируем текст на кнопке

    // Текст для пользователя (с увеличенным размером шрифта и расстоянием)
    sf::Text textName("Name: " + man.getName(), font, 32);
    textName.setFillColor(sf::Color::White);
    textName.setPosition(window.getSize().x / 2 - textName.getGlobalBounds().width / 2, 30); // Центрируем текст

    sf::Text textAge("Age: " + std::to_string(man.getAge()), font, 32);
    textAge.setFillColor(sf::Color::White);
    textAge.setPosition(window.getSize().x / 2 - textAge.getGlobalBounds().width / 2, 90); // Центрируем текст

    sf::Text textHeight("Height: " + std::to_string(man.getHeight()) + " cm", font, 32);
    textHeight.setFillColor(sf::Color::White);
    textHeight.setPosition(window.getSize().x / 2 - textHeight.getGlobalBounds().width / 2, 150); // Центрируем текст

    sf::Text textWeight("Weight: " + std::to_string(man.getWeight()) + " kg", font, 32);
    textWeight.setFillColor(sf::Color::White);
    textWeight.setPosition(window.getSize().x / 2 - textWeight.getGlobalBounds().width / 2, 210); // Центрируем текст

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
        window.draw(backgroundSprite);
        window.draw(textName);
        window.draw(textAge);
        window.draw(textHeight);
        window.draw(textWeight);
        window.draw(buttonDone);
        window.draw(textDone);
        window.display();
    }
}

void EditUser(User & man, int& countUsers){
    countUsers = 0;
    std::vector<std::string> values;
    values = getDate();
    man.setName(values[0]);
    man.setAge(std::stoi(values[1]));
    man.setHeight(std::stoi(values[2]));
    man.setWeight(std::stod(values[3]));
    countUsers++;
    recordedToFile(man, countUsers);
}

