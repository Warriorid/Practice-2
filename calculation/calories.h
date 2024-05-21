
#ifndef PRACTICE_2_CALORIES_H
#define PRACTICE_2_CALORIES_H
#include "../Tool/tools.h"
#include <sstream>

const int max_day = 30;

class Calories {
private:
    std::vector<double> receivedCalories;
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




class CaloriesExtractor {
public:
    void readFromFile(Calories& calories, std::ifstream& file, int& day) {
        file >> day;
        file.ignore();

        std::string line;
        std::getline(file, line);

        std::istringstream iss_received(line);
        for (size_t i = 0; i < 30; ++i) {
            double value;
            iss_received >> value;
            calories.getReceivedCalories()[i] = value;
        }

        std::getline(file, line);
        std::istringstream iss_spent(line);
        for (size_t i = 0; i < 30; ++i) {
            double value;
            iss_spent >> value;
            calories.getSpentCalories()[i] = value;
        }
    }
};
#endif
