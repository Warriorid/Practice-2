#include "Graphic.h"


void menu(UsersModule& user, int& countUsers) {
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("image1.jpg")) {
        return;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Fitness Assistant/Menu ");

    // Кнопка "Add User"
    sf::RectangleShape buttonAddUser(sf::Vector2f(200, 50));
    buttonAddUser.setPosition(300, 50);
    buttonAddUser.setFillColor(sf::Color(0, 0, 0, 200));

    // Кнопка "Delete User"
    sf::RectangleShape buttonDeleteUser(sf::Vector2f(200, 50));
    buttonDeleteUser.setPosition(300, 150);
    buttonDeleteUser.setFillColor(sf::Color(0, 0, 0, 200));

    // Кнопка "Display Users"
    sf::RectangleShape buttonDisplayUsers(sf::Vector2f(200, 50));
    buttonDisplayUsers.setPosition(300, 250);
    buttonDisplayUsers.setFillColor(sf::Color(0, 0, 0, 200));

    // Кнопка "Add Date of Day"
    sf::RectangleShape buttonAddDateOfDay(sf::Vector2f(200, 50));
    buttonAddDateOfDay.setPosition(300, 350);
    buttonAddDateOfDay.setFillColor(sf::Color(0, 0, 0, 200));

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

    sf::Text textDisplayUsers("Display Users", font, 20);
    textDisplayUsers.setFont(font);
    textDisplayUsers.setPosition(buttonDisplayUsers.getPosition().x + 25, buttonDisplayUsers.getPosition().y + 10);

    sf::Text textAddDateOfDay("Add Date of Day", font, 20);
    textAddDateOfDay.setFont(font);
    textAddDateOfDay.setPosition(buttonAddDateOfDay.getPosition().x + 10, buttonAddDateOfDay.getPosition().y + 10);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (buttonAddUser.getGlobalBounds().contains(mousePos)) {
                    addUser();
                } else if (buttonDeleteUser.getGlobalBounds().contains(mousePos)) {
                    user.deleteUser();
                } else if (buttonDisplayUsers.getGlobalBounds().contains(mousePos)) {
                    user.displayUsers();
                } else if (buttonAddDateOfDay.getGlobalBounds().contains(mousePos)) {
                    //add_date_of_day(); // Вызов функции add_date_of_day
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
        window.display();
    }
}