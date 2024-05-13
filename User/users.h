#ifndef PRACTICE_2_users
#define PRACTICE_2_users
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
    void addUserFromInput(int &countUsers) {
        std::string name;
        int age, height;
        float weight;
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cout << "Enter height (in centimetre): ";
        std::cin >> height;
        std::cout << "Enter Weight (в kg): ";
        std::cin >> weight;
        User newUser(name, age, height, weight);
        users.push_back(newUser);
        countUsers++;
    }

    void deleteUser() {
        for (int i = 0; i < users.size(); i++) {
            std::cout << i << " - " << users[i].getName() << std::endl;
        }

        int index;
        std::cout << "Enter number of user: ";
        std::cin >> index;

        if (index >= 0 && index < users.size()) {
            users.erase(users.begin() + index);
            std::cout << "User deleted." << std::endl;
        } else {
            std::cout << "Error index." << std::endl;
        }
    }

    void displayUsers() {
        if(users.size()==0){
            std::cout << "list empty"<< std::endl << std::endl;
            return;
        }
        for (int i = 0; i < users.size(); i++) {
            std::cout << "User " << i + 1 << ": " << users[i].getName() << ", " << users[i].getAge() << " years old, " << users[i].getWeight() << " kg" << std::endl;
        }
    }

    void editUser(){
        for (int i = 0; i < users.size(); i++) {
            std::cout << i << " - " << users[i].getName() << std::endl;
        }
        std::cout << "Enter index of user: ";
        int index, Age, Height;
        std::string Name;
        float Weight;
        std::cin >> index;
        std::cout << "Enter name: ";
        std::cin >> Name;
        std::cout << "Enter age: ";
        std::cin >> Age;
        std::cout << "Enter height (in centimetre): ";
        std::cin >> Height;
        std::cout << "Enter Weight (в kg): ";
        std::cin >> Weight;
        if (index >= 0 && index < users.size()) {
            users[index].setName(Name);
            users[index].setAge(Age);
            users[index].setWeight(Weight);
        }
    }
};


#endif

