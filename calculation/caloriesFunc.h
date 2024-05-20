
#ifndef PRACTICE_2_CALORIESFUNC_H
#define PRACTICE_2_CALORIESFUNC_H
#include <sstream>
void statistic(Calories& calories, User& man);

void add_date_of_day(int & day, int& countUsers, Calories& calories, User& man);

void deleteCalories(Calories & calories, int& day);
void more(Calories& calories, User& man);

void readFileForCalories(int & day, Calories& calories);
void recordedToFileForCalories(int & day, Calories& calories);
double sumKg(Calories& calories);
#endif //PRACTICE_2_CALORIESFUNC_H