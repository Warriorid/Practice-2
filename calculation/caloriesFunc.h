
#ifndef PRACTICE_2_CALORIESFUNC_H
#define PRACTICE_2_CALORIESFUNC_H

void statistic();

void add_date_of_day(int & day, int& countUsers, Calories& calories);

void deleteCalories(Calories & calories, int& day);


void readFileForCalories(int & day);
void recordedToFileForCalories(int & day, Calories& calories);
#endif //PRACTICE_2_CALORIESFUNC_H