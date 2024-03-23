#include "users.h"


void calling_functions(UsersModule& user, int& countUsers){
    int choice;
    do {
        std::cout << "1. Add user" << std::endl;
        std::cout << "2. Delete user" << std::endl;
        std::cout << "3. Edit date about user" << std::endl;
        std::cout << "4. Print date about users" << std::endl;
        std::cout << "5. training" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << std::endl;

        switch (choice) {
            case 1:
                user.addUserFromInput(countUsers);
                break;
            case 2:
                user.deleteUser();
                break;
            case 3:
                user.editUser();
                break;
            case 4:
                user.displayUsers();
                break;
            case 5:

                break;
            case 6:

                break;
            case 0:
                std::cout << "Exiting..." << std::endl;
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again." << std::endl << std::endl;
                break;
        }
    } while (choice != 0);
}
