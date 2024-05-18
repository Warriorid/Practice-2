
#ifndef PRACTICE_2_CALORIES_H
#define PRACTICE_2_CALORIES_H
#include "../Tool/tools.h"

const int max_day = 30;

class Calories {
private:
    std::vector<double> receivedCalories; // Более информативное имя
    std::vector<double> spentCalories;

public:
    Calories() {
        receivedCalories.resize(max_day, 0);
        spentCalories.resize(max_day, 0);
    }

    std::vector<double>& getReceivedCalories() { return receivedCalories; }
    std::vector<double>& getSpentCalories() { return spentCalories; }

    void setReceivedCalories(std::vector<double> g) { receivedCalories = g; }
    void setSpentCalories(std::vector<double> s) { spentCalories = s; }
};


#endif //PRACTICE_2_CALORIES_H
