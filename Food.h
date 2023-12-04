#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"

using namespace std;

class Food
{
    private:
        objPos foodPos;
        objPosArrayList* foodBucket;
        GameMechs* GMref;

    public:
        Food(GameMechs* thisGMRef);
        ~Food();

        void generateFood(objPosArrayList* playerBody);
        void getFoodPos(objPos &returnPos, int num);
};

#endif