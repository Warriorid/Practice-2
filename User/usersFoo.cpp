

#include "users.h"
#include "../Tool/tools.h"

void addUser(User & man, int& countUsers){

    std::vector<std::string> values;
    values = getDate();
    man.setName(values[0]);
    man.setAge(std::stoi(values[1]));
    man.setHeight(std::stoi(values[2]));
    man.setWeight(std::stod(values[3]));
    countUsers++;
    recordedToFile(man, countUsers);

}
