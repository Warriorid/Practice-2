
#ifndef PRACTICE_2_TOOLS_H
#define PRACTICE_2_TOOLS_H
#include<fstream>
#include <SFML/Graphics.hpp>
#include "../User/users.h"
std::vector<std::string> getDate();
void recordedToFile(User & man, int & countUsers);
void readFile(User & man, int & countUsers);
void inputDate();

#endif //PRACTICE_2_TOOLS_H
