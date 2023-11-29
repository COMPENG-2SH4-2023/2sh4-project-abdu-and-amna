#include "Player.h"
#include "MacUILib.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef-> getBoardSizeY() / 2, '@');

}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x,playerPos.y,playerPos.symbol);
    // return the reference to the playerPos arrray list
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
    switch(myDir)
    {
        case UP:
            playerPos.y--;
            if (playerPos.y <= 0)
            {
                playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;  
        case LEFT:
            playerPos.x--;
            if (playerPos.x <= 0)
            {
                playerPos.x =  mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;  
        case DOWN:
            playerPos.y++;
            if (playerPos.y >= mainGameMechsRef->getBoardSizeY() - 1)
            {
                playerPos.y = 1;
            }
            break;  
        case RIGHT:
            playerPos.x++;
            if (playerPos.x >= mainGameMechsRef->getBoardSizeX())
            {
                playerPos.x =  1;
            }
            break;    
        default:
            break;
            
        }

}


