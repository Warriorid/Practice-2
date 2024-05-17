#ifndef PRACTICE_2_users
#define PRACTICE_2_users
#include <SFML/Graphics.hpp>
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
    User(){name = "-"; age = 0; height=0; weight=0; }
    std::string getName() { return name; }
    void setName(const std::string n) { name = n; }
    int getAge() { return age; }
    void setAge(int a) { age = a; }
    int getHeight() { return height; }
    void setHeight(int b) { height = b; }
    float getWeight() { return weight; }
    void setWeight(float w) { weight = w; }

};






void addUser(User & man, int& countUsers);
void Delete(User & man, int& countUsers);
void DisplayUser(User & man, int& countUsers);
void EditUser(User & man, int& countUsers);
#endif

