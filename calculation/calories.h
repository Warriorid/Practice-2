
#ifndef PRACTICE_2_CALORIES_H
#define PRACTICE_2_CALORIES_H
#include "../Tool/tools.h"


class Calories{
private:
    std::vector<int> getCalories;
    std::vector<int> spentCalories;
    const int max_day = 30;
public:
    Calories(){
        for(int i = 0; i < max_day;i++) {
            getCalories[i] = 0;
            spentCalories[i] = 0;
        }
    }
    std::vector<int> get_getCalorie() { return getCalories; }
    std::vector<int> get_spentCalorie() { return spentCalories; }
    void set_getCalorie( std::vector<int> g){ getCalories = g;}
    void set_spentCalorie(std::vector<int> s){ spentCalories = s;}

};


void statistic();

void add_date_of_day(int & day);

#endif //PRACTICE_2_CALORIES_H
