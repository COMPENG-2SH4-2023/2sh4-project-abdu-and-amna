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

    //foodPos.setObjPos(-1, -1, 'o');
}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    score = 0;
    loseFlag = false;
    boardSizeX = boardX;
    boardSizeY = boardY;
    
    //foodPos.setObjPos(-1, -1, 'o');
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

void GameMechs::generateFood(objPos blockOFF)
{
    // genereate random x and y coord, and make sure they are NOT border or blockOFF pos.

    // check x and y against 0 and baordsizex/y

    // remember, in objPos class you have an is PosEqual() method. use this instead of compaying element-by-element
    // for your convenience
    /*int xPos, yPos;

    while (1)
    {
        xPos = rand() % (boardSizeX - 2) + 1;
        yPos = rand() % (boardSizeY - 2) + 1;

        if (xPos == blockOFF.x && yPos == blockOFF.y || xPos>= boardSizeX || xPos <= 0 || yPos >= boardSizeY || yPos <= 0) {
                continue; 
            }
    }
    foodPos.setObjPos(xPos, yPos, 'o');*/
}

void GameMechs::getFoodPos(objPos &returnPos)
{

}