#include "Player.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef, Food* food)
{
    mainGameMechsRef = thisGMRef;
    foodControl = food;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '*');
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);
    foodControl->generateFood(playerPosList);
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
    //MacUILib_printf(input);
    mainGameMechsRef->clearInput();
}

void Player::movePlayer()
{
    objPos headPos;
    playerPosList->getHeadElement(headPos);
    if(checkSelfCollision()){
        mainGameMechsRef->setLoseFlag();
    }
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
            if (headPos.x >= mainGameMechsRef->getBoardSizeX() - 1)
            {
                headPos.x =  1;
            }
            break;
        case STOP:    
        default:
            break;
    }
    int num;
    if (checkFoodConsumption(num)){
        foodControl->generateFood(playerPosList);
        specialCharacterCases(num);
    }
    playerPosList->insertHead(headPos);
    playerPosList->removeTail();
}

bool Player::checkFoodConsumption(int &num)
{
    objPos headPos;
    playerPosList->getHeadElement(headPos);

    for(int i = 0; i < 3; i++){
        objPos foodPos;
        foodControl->getFoodPos(foodPos, i);
        if (headPos.x == foodPos.x && headPos.y == foodPos.y){
            num = i;
            return true;
        }
    }

    return false;
}

void Player::increasePlayerLength() {
    objPos headPos;
    playerPosList->getHeadElement(headPos);
    playerPosList->insertHead(headPos);
}

bool Player::checkSelfCollision() {
    objPos headPos;
    playerPosList->getHeadElement(headPos);
    
    for (int k = 1; k < playerPosList->getSize(); k++)
    {
        objPos bodyPos;
        playerPosList->getElement(bodyPos, k);
        if (headPos.x == bodyPos.x && headPos.y == bodyPos.y)
        {
            return true;
        }
    }
    return false;
}

void Player::specialCharacterCases(int num){
    objPos headPos;
    playerPosList->getHeadElement(headPos);

    objPos foodPos;
    foodControl->getFoodPos(foodPos, num);

    if(foodPos.symbol == 'o'){
        increasePlayerLength();
        mainGameMechsRef->incrementScore();
    }

    else if(foodPos.symbol == '.'){
        if (playerPosList->getSize() > 1){
            if (playerPosList->getSize() > 3){
                for(int i = 0; i < 3; i++){
                    playerPosList->removeTail();
                }
            }
            else{
                for(int i = 0; i < playerPosList->getSize(); i++){
                    playerPosList->removeTail();
                }
            }
        }
        for(int i = 0; i < 3; i++){
            mainGameMechsRef->incrementScore();
        }
    }
    else{
        for(int i = 0; i < 3; i++){
            increasePlayerLength();
        }
        mainGameMechsRef->incrementScore();
    }
}
