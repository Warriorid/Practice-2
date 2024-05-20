#include "Graphic.h"
#include "../User/usersFoo.h"
#include "..//calculation/caloriesFunc.h"


void menu(User & man, int& countUsers, int &day, Calories calories) {
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("i1.png")) {
        return;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant/Menu ");

    // Calculate center of the window
    float centerX = window.getSize().x / 2.0f;
    float centerY = window.getSize().y / 2.0f;

    // Button dimensions and spacing
    float buttonWidth = 200;
    float buttonHeight = 50;
    float buttonSpacing = 40; // Adjust this for button spacing

    // Кнопка "Add User"
    sf::RectangleShape buttonAddUser(sf::Vector2f(buttonWidth, buttonHeight));
    buttonAddUser.setPosition(centerX - buttonWidth / 2, centerY - 250);
    buttonAddUser.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Delete User"
    sf::RectangleShape buttonDeleteUser(sf::Vector2f(buttonWidth, buttonHeight));
    buttonDeleteUser.setPosition(centerX - buttonWidth / 2, buttonAddUser.getPosition().y + buttonHeight + buttonSpacing);
    buttonDeleteUser.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Display Users"
    sf::RectangleShape buttonDisplayUsers(sf::Vector2f(buttonWidth, buttonHeight));
    buttonDisplayUsers.setPosition(centerX - buttonWidth / 2, buttonDeleteUser.getPosition().y + buttonHeight + buttonSpacing);
    buttonDisplayUsers.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Add Date of Day"
    sf::RectangleShape buttonAddDateOfDay(sf::Vector2f(buttonWidth, buttonHeight));
    buttonAddDateOfDay.setPosition(centerX - buttonWidth / 2, buttonDisplayUsers.getPosition().y + buttonHeight + buttonSpacing);
    buttonAddDateOfDay.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Edit User"
    sf::RectangleShape buttonEditUser(sf::Vector2f(buttonWidth, buttonHeight));
    buttonEditUser.setPosition(centerX - buttonWidth / 2, buttonAddDateOfDay.getPosition().y + buttonHeight + buttonSpacing);
    buttonEditUser.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Statistics"
    sf::RectangleShape buttonStatistics(sf::Vector2f(buttonWidth, buttonHeight));
    buttonStatistics.setPosition(centerX - buttonWidth / 2, buttonEditUser.getPosition().y + buttonHeight + buttonSpacing);
    buttonStatistics.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Exit"
    sf::RectangleShape buttonExit(sf::Vector2f(buttonWidth, buttonHeight));
    buttonExit.setPosition(centerX - buttonWidth / 2, buttonStatistics.getPosition().y + buttonHeight + buttonSpacing);
    buttonExit.setFillColor(sf::Color(82, 82, 82, 200));

    // Шрифт
    sf::Font font;
    if (!font.loadFromFile("Arial_Black.ttf")) return;

    // Текст для кнопок
    sf::Text textAddUser("Add User", font, 20);
    textAddUser.setFont(font);
    textAddUser.setPosition(buttonAddUser.getPosition().x + 50, buttonAddUser.getPosition().y + 10);

    sf::Text textDeleteUser("Delete User", font, 20);
    textDeleteUser.setFont(font);
    textDeleteUser.setPosition(buttonDeleteUser.getPosition().x + 25, buttonDeleteUser.getPosition().y + 10);

    sf::Text textDisplayUsers("Display User", font, 20);
    textDisplayUsers.setFont(font);
    textDisplayUsers.setPosition(buttonDisplayUsers.getPosition().x + 25, buttonDisplayUsers.getPosition().y + 10);

    sf::Text textAddDateOfDay("Add Date of Day", font, 20);
    textAddDateOfDay.setFont(font);
    textAddDateOfDay.setPosition(buttonAddDateOfDay.getPosition().x + 10, buttonAddDateOfDay.getPosition().y + 10);

    sf::Text textEditUser("Edit User", font, 20);
    textEditUser.setFont(font);
    textEditUser.setPosition(buttonEditUser.getPosition().x + 50, buttonEditUser.getPosition().y + 10);

    sf::Text textStatistics("Statistics", font, 20);
    textStatistics.setFont(font);
    textStatistics.setPosition(buttonStatistics.getPosition().x + 40, buttonStatistics.getPosition().y + 10);

    sf::Text textExit("Exit", font, 20);
    textExit.setFont(font);
    textExit.setPosition(buttonExit.getPosition().x + 80, buttonExit.getPosition().y + 10);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (buttonAddUser.getGlobalBounds().contains(mousePos)) {
                    addUser(man, countUsers);
                } else if (buttonDeleteUser.getGlobalBounds().contains(mousePos)) {
                    Delete(man, countUsers, day, calories);
                } else if (buttonDisplayUsers.getGlobalBounds().contains(mousePos)) {
                    DisplayUser(man, countUsers);
                } else if (buttonAddDateOfDay.getGlobalBounds().contains(mousePos)) {
                    add_date_of_day(day, countUsers, calories, man);
                } else if (buttonEditUser.getGlobalBounds().contains(mousePos)) {
                    EditUser(man, countUsers); // Вызов функции editUser
                } else if (buttonStatistics.getGlobalBounds().contains(mousePos)) {
                    statistic(calories, man); // Вызов функции statistics
                } else if (buttonExit.getGlobalBounds().contains(mousePos)) {
                    exit(0);
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(backgroundSprite);
        window.draw(buttonAddUser);
        window.draw(textAddUser);
        window.draw(buttonDeleteUser);
        window.draw(textDeleteUser);
        window.draw(buttonDisplayUsers);
        window.draw(textDisplayUsers);
        window.draw(buttonAddDateOfDay);
        window.draw(textAddDateOfDay);
        window.draw(buttonEditUser);
        window.draw(textEditUser);
        window.draw(buttonStatistics);
        window.draw(textStatistics);
        window.draw(buttonExit);
        window.draw(textExit);
        window.display();
    }
}