
#include "calories.h"


void inputDate(){
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("image5.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    float centerX = window.getSize().x / 2.0f;
    float centerY = window.getSize().y / 2.0f;

    sf::RectangleShape inputField1(sf::Vector2f(200, 30));
    inputField1.setFillColor(sf::Color(82, 82, 82, 200));
    inputField1.setOutlineColor(sf::Color::Black);
    inputField1.setOutlineThickness(2);
    inputField1.setPosition(centerX - inputField1.getSize().x / 2, centerY - 100);

    sf::RectangleShape inputField2(sf::Vector2f(200, 30));
    inputField2.setFillColor(sf::Color(82, 82, 82, 200));
    inputField2.setOutlineColor(sf::Color::Black);
    inputField2.setOutlineThickness(2);
    inputField2.setPosition(centerX - inputField2.getSize().x / 2, centerY + 50);

    sf::RectangleShape inputField3(sf::Vector2f(65, 30));
    inputField3.setFillColor(sf::Color(82, 82, 82, 200));
    inputField3.setOutlineColor(sf::Color::Black);
    inputField3.setOutlineThickness(2);
    inputField3.setPosition(centerX - inputField3.getSize().x / 2, centerY + 200);

    sf::Font font;
    font.loadFromFile("Arial_Black.ttf");

    sf::Text text1("", font, 20);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(inputField1.getPosition().x + 5, inputField1.getPosition().y + 5);

    sf::Text text2("", font, 20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(inputField2.getPosition().x + 5, inputField2.getPosition().y + 5);

    sf::Text buttonText("Done", font, 20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(inputField3.getPosition().x + 5, inputField3.getPosition().y + 5);

    sf::Text label1Text("Calories spent", font, 30);
    label1Text.setFillColor(sf::Color::Black);
    label1Text.setPosition(centerX - label1Text.getGlobalBounds().width / 2, inputField1.getPosition().y - 35);

    sf::Text label2Text("Calories received", font, 30);
    label2Text.setFillColor(sf::Color::Black);
    label2Text.setPosition(centerX - label2Text.getGlobalBounds().width / 2, inputField2.getPosition().y - 35);

    std::string inputString1, inputString2;
    std::vector<std::string> values;

    bool inputField1Active = true;
    bool inputField2Active = false;
    bool donePressed = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (inputField1.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    inputField1Active = true;
                    inputField2Active = false;
                } else if (inputField2.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    inputField1Active = false;
                    inputField2Active = true;
                } else if (inputField3.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    donePressed = true;
                } else {
                    inputField1Active = false;
                    inputField2Active = false;
                }
            } else if (event.type == sf::Event::TextEntered) {
                if (inputField1Active) {
                    if (event.text.unicode == 8 && !inputString1.empty())
                        inputString1.pop_back();
                    else if (event.text.unicode == 13)
                        inputField1Active = false;
                    else
                        inputString1 += static_cast<char>(event.text.unicode);
                    text1.setString(inputString1);
                } else if (inputField2Active) {
                    if (event.text.unicode == 8 && !inputString2.empty())
                        inputString2.pop_back();
                    else if (event.text.unicode == 13)
                        inputField2Active = false;
                    else
                        inputString2 += static_cast<char>(event.text.unicode);
                    text2.setString(inputString2);
                }
            }
        }

        if (donePressed) {
            values.push_back(inputString1);
            values.push_back(inputString2);
            donePressed = false;
            window.close();
            //return values;
        }

        window.clear(sf::Color::White);
        window.draw(backgroundSprite);
        window.draw(inputField1);
        window.draw(inputField2);
        window.draw(inputField3);
        window.draw(text1);
        window.draw(text2);
        window.draw(buttonText);
        window.draw(label1Text);
        window.draw(label2Text);
        window.display();
    }
}

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