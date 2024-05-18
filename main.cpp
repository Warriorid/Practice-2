#include "User/users.h"
#include "Graphic/Graphic.h"
#include "Tool/tools.h"

int main() {
    int day = 0;
    int countUsers = 0;
    User man;
    readFile(man, countUsers);
    readFileForCalories(day);
    menu(man, countUsers, day);
    return 0;
}