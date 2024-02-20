#include <iostream>
#include <string>
#include <random>
#include <time.h>
#include "Dragon.hpp";
#include "ChineseFireball.hpp"
#include "CommonWelsh.hpp"
#include "HungarianHorntail.hpp"


template<typename D>
void TrainDragon(D* dragon) {
    dragon->Train();
}

int main()
{
    srand((unsigned int)time(NULL));

    Dragon* dragons[9];

    ChineseFireBall* fire1 = new ChineseFireBall();
    ChineseFireBall* fire2 = new ChineseFireBall();
    ChineseFireBall* fire3 = new ChineseFireBall();
    dragons[0] = fire1;
    dragons[1] = fire2;
    dragons[2] = fire3;

    CommonWelsh* welsh1 = new CommonWelsh();
    CommonWelsh* welsh2 = new CommonWelsh();
    CommonWelsh* welsh3 = new CommonWelsh();
    dragons[3] = welsh1;
    dragons[4] = welsh2;
    dragons[5] = welsh3;

    HungarianHorntail* horn1 = new HungarianHorntail();
    HungarianHorntail* horn2 = new HungarianHorntail();
    HungarianHorntail* horn3 = new HungarianHorntail();
    dragons[6] = horn1;
    dragons[7] = horn2;
    dragons[8] = horn3;

    for (int i = 0; i < 9; i++) {
        dragons[i]->Print();
        TrainDragon(dragons[i]);
        dragons[i]->Print();
    }
}