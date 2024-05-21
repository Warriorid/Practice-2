
#ifndef PRACTICE_2_TOOLS_H
#define PRACTICE_2_TOOLS_H
#include<fstream>
#include <SFML/Graphics.hpp>
#include "../User/users.h"



class UserExtractor {
public:
    void readFromFile(User& user, std::ifstream& file) {
        int countUsers;
        file >> countUsers;
        file.ignore();

        std::string name;
        std::getline(file, name);
        user.setName(name);

        int age;
        file >> age;
        user.setAge(age);

        int height;
        file >> height;
        user.setHeight(height);

        double weight;
        file >> weight;
        user.setWeight(weight);
    }
};


std::vector<std::string> getDate();
void recordedToFile(User & man, int & countUsers);
void readFile(User & man, int & countUsers);
std::vector<std::string> inputDate();


#endif //PRACTICE_2_TOOLS_H