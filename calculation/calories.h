
#ifndef PRACTICE_2_CALORIES_H
#define PRACTICE_2_CALORIES_H
#include "../Tool/tools.h"

const int max_day = 30;

class Calories {
private:
    std::vector<int> receivedCalories; // Более информативное имя
    std::vector<int> spentCalories;

public:
    Calories() {
        receivedCalories.resize(max_day, 0);
        spentCalories.resize(max_day, 0);
    }

    std::vector<int> getReceivedCalories() const { return receivedCalories; }
    std::vector<int> getSpentCalories() const { return spentCalories; }

    void setReceivedCalories(std::vector<int> g) { receivedCalories = g; }
    void setSpentCalories(std::vector<int> s) { spentCalories = s; }
};

void statistic();

void add_date_of_day(int & day, int& countUsers);

void deleteCalories(Calories & calories, int& day);

#endif //PRACTICE_2_CALORIES_H
