
#include "calories.h"
#include "caloriesFunc.h"


void statistic(Calories& calories, User& man) {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Fitness Assistant");

    // Загружаем фон (если он нужен)
    sf::Texture texture;
    if (!texture.loadFromFile("image8.png")) {
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
    buttonDone.setPosition(window.getSize().x / 2 - buttonDone.getSize().x / 2 - 50,
                           window.getSize().y - buttonDone.getSize().y - 20);
    buttonDone.setFillColor(sf::Color(82, 82, 82, 200));

    // Кнопка "More"
    sf::RectangleShape buttonMore(sf::Vector2f(100, 40));
    buttonMore.setPosition(window.getSize().x / 2 - buttonMore.getSize().x / 2 + 50,
                           window.getSize().y - buttonMore.getSize().y - 20);
    buttonMore.setFillColor(sf::Color(82, 82, 82, 200));

    // Шрифт для текста
    sf::Font font;
    if (!font.loadFromFile("Arial_Black.ttf")) {
        return;
    }

    // Текст для кнопки "Done"
    sf::Text textDone("Done", font, 20);
    textDone.setFillColor(sf::Color::White);
    textDone.setPosition(buttonDone.getPosition().x + 25, buttonDone.getPosition().y + 5);

    // Текст для кнопки "More"
    sf::Text textMore("More...", font, 20);
    textMore.setFillColor(sf::Color::White);
    textMore.setPosition(buttonMore.getPosition().x + 25, buttonMore.getPosition().y + 5);

    // Фон для текста
    sf::RectangleShape textBackground(sf::Vector2f(600, 555));
    textBackground.setFillColor(sf::Color(255, 255, 255, 150)); // Полупрозрачный белый
    textBackground.setPosition(window.getSize().x / 2 - textBackground.getSize().x / 2,
                               window.getSize().y / 2 - textBackground.getSize().y / 2 - 50);

    // Строка для вывода информации о калориях
    std::string caloriesInfo = "Calories:\n";

    // Цикл по дням
    for (int day = 0; day < max_day/2; ++day) {
        caloriesInfo += "Day " + std::to_string(day + 1) + ": ";
        caloriesInfo += "Received - " + std::to_string(calories.getReceivedCalories()[day]) + ", ";
        caloriesInfo += "Spent - " + std::to_string(calories.getSpentCalories()[day]) + "\n";
    }

    // Текст для отображения калорий
    sf::Text textCalories(caloriesInfo, font, 20);
    textCalories.setFillColor(sf::Color::Black);
    textCalories.setPosition(window.getSize().x / 2 - textCalories.getLocalBounds().width / 2,
                             window.getSize().y / 2 - textCalories.getLocalBounds().height / 2 - 100); // Центрируем текст

    std::string weightText = "Your weight now: " + std::to_string(man.getWeight());
    sf::Text textWeight(weightText, font, 30);
    textWeight.setFillColor(sf::Color::Black);
    textWeight.setPosition(window.getSize().x / 2 - textWeight.getLocalBounds().width / 2,
                           500); // Центрируем текст

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                if (buttonDone.getGlobalBounds().contains(mousePos)) {
                    window.close();
                } else if (buttonMore.getGlobalBounds().contains(mousePos)) {
                    //more(); // Вызов функции more()
                }
            }
        }

        window.clear(sf::Color::White);

        // Рисуем фон (если есть)
        window.draw(sprite);

        // Рисуем фон для текста
        window.draw(textBackground);

        // Рисуем текст о калориях
        window.draw(textCalories);

        // Рисуем кнопку "Done"
        window.draw(buttonDone);
        window.draw(textDone);

        // Рисуем кнопку "More"
        window.draw(buttonMore);
        window.draw(textMore);
        window.draw(textWeight);
        window.display();
    }
}


void add_date_of_day(int& day, int& countUsers, Calories& calories, User& man){
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
    double Kg = sumKg(calories);
    man.setWeight(man.getWeight()-Kg);
    recordedToFile(man, countUsers);
    recordedToFileForCalories(day, calories);
}



void deleteCalories(Calories & calories, int& day){
    day = 0;
    for(int i = 0; i < 30;i++) {
        calories.getReceivedCalories()[i] = 0;
        calories.getSpentCalories()[i] = 0;
    }
    recordedToFileForCalories(day, calories);
}

void recordedToFileForCalories(int & day, Calories& calories) {
    std::ofstream file("date_about_calories.txt", std::ios::trunc);
    if (!file.is_open()) {
        return;
    }

    file << day << '\n';

    for (size_t i = 0; i < 30; ++i) {
        file << calories.getReceivedCalories()[i] << " ";
    }
    file << '\n';

    for (size_t i = 0; i < calories.getSpentCalories().size(); ++i) {
        file << calories.getSpentCalories()[i] << " ";
    }
    file << '\n';

    file.close();
}

void readFileForCalories(int &day, Calories &calories) {
    std::ifstream file("date_about_calories.txt");
    if (!file.is_open()) {
        return; // Файл не найден
    }

    file >> day; // Считываем день
    file.ignore(); // Игнорируем символ новой строки

    std::string line;
    std::getline(file, line); // Считываем строку с калориями

    std::istringstream iss_received(line); // Поток для receivedCalories
    for (size_t i = 0; i < 30; ++i) {
        double value;
        iss_received >> value;
        calories.getReceivedCalories()[i] = value;
    }

    std::getline(file, line); // Считываем следующую строку с калориями
    std::istringstream iss_spent(line); // Поток для spentCalories
    for (size_t i = 0; i < 30; ++i) {
        double value;
        iss_spent >> value;
        calories.getSpentCalories()[i] = value;
    }

    file.close();
}

double sumKg(Calories& calories){
    double spent, get;
    for (int i = 0; i<30;i++){
        spent+=calories.getSpentCalories()[i];
    }
    for (int i = 0; i<30;i++){
        get+=calories.getReceivedCalories()[i];
    }
    double sum = (spent-get)/7700;
    return sum;

}