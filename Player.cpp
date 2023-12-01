#include "Player.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

}


Player::~Player()
{
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
}




void Player::updatePlayerDir()
{

    char input = mainGameMechsRef->getInput();

    // PPA3 input processing logic
    switch(input)
    {
        case 'w':
            if(myDir != UP && myDir != DOWN)
                myDir = UP;
            break;
        case 'a':
            if(myDir != LEFT && myDir != RIGHT)
                myDir = LEFT;
            break;
        case 's':
            if(myDir != UP && myDir != DOWN)
                myDir = DOWN;
            break;
        case 'd':
            if(myDir != RIGHT && myDir != LEFT)
                myDir = RIGHT;
            break;
        
        
        default:
            break;
    }
    mainGameMechsRef->clearInput();
}

void Player::movePlayer()
{
    objPos headPos;
    playerPosList->getHeadElement(headPos);
    switch(myDir)
    {
        
        case UP:
            headPos.y--;
            if (headPos.y <= 0)
            {
                headPos.y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;  
        case LEFT:
            headPos.x--;
            if (headPos.x <= 0)
            {
                headPos.x =  mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;  
        case DOWN:
            headPos.y++;
            if (headPos.y >= mainGameMechsRef->getBoardSizeY() - 1)
            {
                headPos.y = 1;
            }
            break;  
        case RIGHT:
            headPos.x++;
            if (headPos.x >= mainGameMechsRef->getBoardSizeX())
            {
                headPos.x =  1;
            }
            break;
        case STOP:    
        default:
            break;
    }
    objPos foodPos;
    mainGameMechsRef->getFoodPos(foodPos);
    //objPosArrayList* playerBody = getPlayerPos();
    //objPos tempPos;
    //playerBody->getHeadElement(tempPos);
    if(headPos.x == foodPos.x && headPos.y == foodPos.y)
    {
        playerPosList->insertHead(headPos);
        mainGameMechsRef->incrementScore();
        mainGameMechsRef->generateFood(playerPosList);


    }
    else
    {
        playerPosList->insertHead(headPos);
        playerPosList->removeTail();
    }
        

    
}


