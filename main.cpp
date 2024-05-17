#include "User/users.h"
#include "Graphic/Graphic.h"
#include "Tool/tools.h"

int main() {
    int countUsers = 0;
    User man;
    readFile(man, countUsers);
    menu(man, countUsers);
    return 0;
}