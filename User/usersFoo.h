
#ifndef PRACTICE_2_USERSFOO_H
#define PRACTICE_2_USERSFOO_H
#include "users.h"
#include "..//calculation/calories.h"
#include "..//calculation/caloriesFunc.h"

void addUser(User & man, int& countUsers);
void Delete(User & man, int& countUsers, int& day, Calories calories);
void DisplayUser(User & man, int& countUsers);
void EditUser(User & man, int& countUsers);

#endif //PRACTICE_2_USERSFOO_H
