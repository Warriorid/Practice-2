#include "Graphic.h"


void menu(UsersModule& user, int& countUsers) {
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("img.png")) {
        return;
    }
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant/Menu ");

    // Кнопка "Add User"
    sf::RectangleShape buttonAddUser(sf::Vector2f(200, 50));
    buttonAddUser.setPosition(300, 50);
    buttonAddUser.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Delete User"
    sf::RectangleShape buttonDeleteUser(sf::Vector2f(200, 50));
    buttonDeleteUser.setPosition(300, 150);
    buttonDeleteUser.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Display Users"
    sf::RectangleShape buttonDisplayUsers(sf::Vector2f(200, 50));
    buttonDisplayUsers.setPosition(300, 250);
    buttonDisplayUsers.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Add Date of Day"
    sf::RectangleShape buttonAddDateOfDay(sf::Vector2f(200, 50));
    buttonAddDateOfDay.setPosition(300, 350);
    buttonAddDateOfDay.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Edit User"
    sf::RectangleShape buttonEditUser(sf::Vector2f(200, 50));
    buttonEditUser.setPosition(300, 450);
    buttonEditUser.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "Statistics"
    sf::RectangleShape buttonStatistics(sf::Vector2f(200, 50));
    buttonStatistics.setPosition(300, 550);
    buttonStatistics.setFillColor(sf::Color(82, 82, 82, 200));

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

    sf::Text textEditUser("Edit User", font, 20);
    textEditUser.setFont(font);
    textEditUser.setPosition(buttonEditUser.getPosition().x + 50, buttonEditUser.getPosition().y + 10);

    sf::Text textStatistics("Statistics", font, 20);
    textStatistics.setFont(font);
    textStatistics.setPosition(buttonStatistics.getPosition().x + 40, buttonStatistics.getPosition().y + 10);

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
                } else if (buttonEditUser.getGlobalBounds().contains(mousePos)) {
                    user.editUser(); // Вызов функции editUser
                } else if (buttonStatistics.getGlobalBounds().contains(mousePos)) {
                    //statistics(); // Вызов функции statistics
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
        window.display();
    }
}