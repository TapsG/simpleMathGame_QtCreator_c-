#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "square.h"
#include <vector>



class gamelogic
{
public:
    gamelogic();
    ~gamelogic();


    void init_logic_board();

    std::vector<std::vector<square>> get_board();
    std::vector<std::vector<square>> new_board();



    int get_total_sum();

    void add_to_sum(int s);


private:

    int logic_size = 10;

    std::vector<std::vector<square>> logic_board;

    int total_sum = 0;
};

#endif // GAMELOGIC_H
