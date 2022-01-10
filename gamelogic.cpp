#include "gamelogic.h"
#include <random>

gamelogic::gamelogic():
    logic_size(10)

{

}

gamelogic::~gamelogic()
{

}

void gamelogic::init_logic_board(){

    for(int i = 0; i < logic_size; i++){
        logic_board.push_back({});
        for(int j = 0; j < logic_size; j++){
            square sqr;
            logic_board.at(i).push_back(sqr);
        }
    }
}

std::vector<std::vector<square>> gamelogic::get_board(){
    init_logic_board();
    return logic_board;
}

std::vector<std::vector<square>> gamelogic::new_board(){
    logic_board.clear();
    init_logic_board();
    return logic_board;
}
int gamelogic::get_total_sum(){
    for(int i = 0; i < logic_size; i++){
        for(int j = 0; j < logic_size; j++){
            total_sum += logic_board.at(i).at(j).get_number();
        }
    }
    return total_sum;
}

void gamelogic::add_to_sum(int s){
    total_sum += s;

}
