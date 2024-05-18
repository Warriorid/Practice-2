#include "User/users.h"
#include "Graphic/Graphic.h"
#include "Tool/tools.h"

int main() {
    const int max_day = 30;
    int day;
    int countUsers = 0;
    User man;
    readFile(man, countUsers);
    menu(man, countUsers, day);
    return 0;
}