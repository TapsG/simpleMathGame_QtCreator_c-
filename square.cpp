#include "square.h"
#include "gamelogic.h"

#include <iostream>

square::square():
    number(rand() % 201 + (-100))
{

}
square::~square()
{

}

int square::get_number(){
    return number;
}
