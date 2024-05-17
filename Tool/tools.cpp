

#include "tools.h"


std::vector<std::string> getDate() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant");


    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("img.png");
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);


    float centerX = window.getSize().x / 2.0f;
    float centerY = window.getSize().y / 2.0f;


    sf::RectangleShape inputField1(sf::Vector2f(200, 30));
    inputField1.setFillColor(sf::Color(82, 82, 82, 200));
    inputField1.setOutlineColor(sf::Color::Black);
    inputField1.setOutlineThickness(2);
    inputField1.setPosition(centerX - inputField1.getSize().x / 2, centerY - 200);

    sf::RectangleShape inputField2(sf::Vector2f(200, 30));
    inputField2.setFillColor(sf::Color(82, 82, 82, 200));
    inputField2.setOutlineColor(sf::Color::Black);
    inputField2.setOutlineThickness(2);
    inputField2.setPosition(centerX - inputField2.getSize().x / 2, centerY - 100);

    sf::RectangleShape inputField3(sf::Vector2f(200, 30));
    inputField3.setFillColor(sf::Color(82, 82, 82, 200));
    inputField3.setOutlineColor(sf::Color::Black);
    inputField3.setOutlineThickness(2);
    inputField3.setPosition(centerX - inputField3.getSize().x / 2, centerY);

    sf::RectangleShape inputField4(sf::Vector2f(200, 30));
    inputField4.setFillColor(sf::Color(82, 82, 82, 200));
    inputField4.setOutlineColor(sf::Color::Black);
    inputField4.setOutlineThickness(2);
    inputField4.setPosition(centerX - inputField4.getSize().x / 2, centerY+100);

    sf::RectangleShape inputField5(sf::Vector2f(65, 30));
    inputField5.setFillColor(sf::Color(82, 82, 82, 200));
    inputField5.setOutlineColor(sf::Color::Black);
    inputField5.setOutlineThickness(2);
    inputField5.setPosition(centerX - inputField5.getSize().x / 2, centerY + 200);


    sf::Font font;
    if (!font.loadFromFile("Arial_Black.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    sf::Text text1("", font, 20);
    text1.setFillColor(sf::Color::White);
    text1.setPosition(inputField1.getPosition().x + 5, inputField1.getPosition().y + 5);

    sf::Text text2("", font, 20);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(inputField2.getPosition().x + 5, inputField2.getPosition().y + 5);

    sf::Text text3("", font, 20);
    text3.setFillColor(sf::Color::White);
    text3.setPosition(inputField3.getPosition().x + 5, inputField3.getPosition().y + 5);

    sf::Text text4("", font, 20);
    text4.setFillColor(sf::Color::White);
    text4.setPosition(inputField4.getPosition().x + 5, inputField4.getPosition().y + 5);

    sf::Text buttonText("Done", font, 20);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(inputField5.getPosition().x + 5, inputField5.getPosition().y + 5);


    sf::Text label1("Name:", font, 30);
    label1.setFillColor(sf::Color::Black);
    label1.setPosition(centerX - label1.getGlobalBounds().width / 2, inputField1.getPosition().y - 35);

    sf::Text label2("Age:", font, 30);
    label2.setFillColor(sf::Color::Black);
    label2.setPosition(centerX - label2.getGlobalBounds().width / 2, inputField2.getPosition().y - 35);

    sf::Text label3("Height:", font, 30);
    label3.setFillColor(sf::Color::Black);
    label3.setPosition(centerX - label3.getGlobalBounds().width / 2, inputField3.getPosition().y - 35);

    sf::Text label4("Weight:", font, 30);
    label4.setFillColor(sf::Color::Black);
    label4.setPosition(centerX - label4.getGlobalBounds().width / 2, inputField4.getPosition().y - 35);


    std::string inputString1, inputString2, inputString3, inputString4;
    std::vector<std::string> values;


    bool inputField1Active = true;
    bool inputField2Active = false;
    bool inputField3Active = false;
    bool inputField4Active = false;

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
                    inputField3Active = false;
                    inputField4Active = false;
                } else if (inputField2.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    inputField1Active = false;
                    inputField2Active = true;
                    inputField3Active = false;
                    inputField4Active = false;
                } else if (inputField3.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    inputField1Active = false;
                    inputField2Active = false;
                    inputField3Active = true;
                    inputField4Active = false;
                } else if (inputField4.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    inputField1Active = false;
                    inputField2Active = false;
                    inputField3Active = false;
                    inputField4Active = true;
                } else if (buttonText.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                    donePressed = true;
                } else {
                    inputField1Active = false;
                    inputField2Active = false;
                    inputField3Active = false;
                    inputField4Active = false;
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
                } else if (inputField3Active) {
                    if (event.text.unicode == 8 && !inputString3.empty())
                        inputString3.pop_back();
                    else if (event.text.unicode == 13)
                        inputField3Active = false;
                    else
                        inputString3 += static_cast<char>(event.text.unicode);
                    text3.setString(inputString3);
                } else if (inputField4Active) {
                    if (event.text.unicode == 8 && !inputString4.empty())
                        inputString4.pop_back();
                    else if (event.text.unicode == 13)
                        inputField4Active = false;
                    else
                        inputString4 += static_cast<char>(event.text.unicode);
                    text4.setString(inputString4);
                }
            }
        }


        if (donePressed) {
            values.push_back(inputString1);
            values.push_back(inputString2);
            values.push_back(inputString3);
            values.push_back(inputString4);
            donePressed = false;
            window.close();
            return values;
        }

        window.clear(sf::Color::White);
        window.draw(backgroundSprite);
        window.draw(inputField1);
        window.draw(inputField2);
        window.draw(inputField3);
        window.draw(inputField4);
        window.draw(inputField5);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(buttonText);
        window.draw(label1);
        window.draw(label2);
        window.draw(label3);
        window.draw(label4);
        window.display();
    }
}


void recordedToFile(User & man, int & countUsers) {

    std::ofstream file("date_about_user.txt", std::ios::out);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }
    file << countUsers << '\n';
    file << man.getName() << '\n';
    file << man.getAge() << '\n';
    file << man.getHeight() << '\n';
    file << man.getWeight() << '\n';


    file.close();
}