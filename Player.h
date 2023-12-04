#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class Player
{
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state

        Player(GameMechs* thisGMRef, Food* food);
        ~Player();

        objPosArrayList* getPlayerPos();
        void updatePlayerDir();
        void movePlayer();
        bool checkFoodConsumption(int &num);
        void increasePlayerLength();
        bool checkSelfCollision();
        void specialCharacterCases(int num);

    private:
        objPosArrayList* playerPosList;   
        enum Dir myDir;
        //objPos foodPos;

        GameMechs* mainGameMechsRef;
        Food* foodControl;
};

#endif