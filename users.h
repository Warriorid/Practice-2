#include <iostream>
#include <string>
#include <vector>


class User {
private:
    std::string name;
    int age;
    int height;
    float weight;

public:
    User(std::string n, int a, int b, float w) : name(n), age(a), height(b), weight(w) {}

    std::string getName() { return name; }
    void setName(std::string n) { name = n; }
    int getAge() { return age; }
    void setAge(int a) { age = a; }
    int getHeight() { return height; }
    void setHeight(int b) { height = b; }
    float getWeight() { return weight; }
    void setWeight(float w) { weight = w; }
};

class UsersModule {
private:
    std::vector<User> users;

public:
    void addUserFromInput() {
        std::string name;
        int age, height;
        float weight;
        std::cout << "Введите имя пользователя: ";
        std::cin >> name;
        std::cout << "Введите возраст пользователя: ";
        std::cin >> age;
        std::cout << "Введите рост пользователя (в см): ";
        std::cin >> height;
        std::cout << "Введите вес пользователя (в кг): ";
        std::cin >> weight;
        User newUser(name, age, height, weight);
        users.push_back(newUser);
    }

};


