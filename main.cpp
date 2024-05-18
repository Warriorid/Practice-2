#include "User/users.h"
#include "Graphic/Graphic.h"
#include "Tool/tools.h"
#include "calculation/caloriesFunc.h"

int main() {
    int day = 0;
    int countUsers = 0;
    User man;
    Calories calories;
    readFile(man, countUsers);
    readFileForCalories(day);
    menu(man, countUsers, day, calories);
    return 0;
}