#include "GameMechs.h"
#include "MacUILib.h"

//think about where to seed the RNG

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    score = 0;
    loseFlag = false;
    boardSizeX = 30;
    boardSizeY = 15;

    foodPos.setObjPos(-1, -1, 'o');
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    score = 0;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    
    foodPos.setObjPos(-1, -1, 'o');
}

// do you need a destructor?
GameMechs::~GameMechs()
{

}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input=MacUILib_getChar();
        if(input == 27){
            setExitTrue();
        }
    }
    return input;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

int GameMechs::getScore()
{
    return score;
}

void GameMechs::incrementScore()
{
    score ++;
}

void GameMechs::generateFood(objPosArrayList* playerBody)
{
    //objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempPos;
    
    int flag = 0;
    bool overlap = false;

    while (flag == 0)
    {
        int x = rand() % (boardSizeX - 2) + 1;
        int y = rand() % (boardSizeY - 2) + 1;

        for (int k = 0; k < playerBody->getSize(); k++)
        {
            objPos tempPos;
            playerBody->getElement(tempPos, k);
            if (x == tempPos.x && y == tempPos.y)
            {
                overlap = true;
                break;
            }
        }

        if (!overlap)
        {
            foodPos.setObjPos(x, y, 'o');
            flag = 1;
        }
        
    }
}     

    


void GameMechs::getFoodPos(objPos &returnPos)
{
    returnPos.setObjPos(foodPos.x, foodPos.y, 'o');
}