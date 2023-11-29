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
                myDir = DOWN;
            break;

        default:
            break;
    }
    /*if(input != '\0') 
    {
        switch(input)
        {                      
            case ' ':  
                mainGameMechsRef->setExitTrue();
                break;
            default:
                break;
        }
        mainGameMechsRef->clearInput();
    }

    if (input == 'd' || input == 'D') {
        mainGameMechsRef->incrementScore();
    }
    if (input == '1') {
        mainGameMechsRef->setLoseFlag();
    }     */   
}

void Player::movePlayer()
{
    switch (myDir)
    {
        case UP:
            playerPos.y--;
            break;
        case LEFT:
            playerPos.x--;
            break;
        case DOWN:
            playerPos.y++;
            break;
        case RIGHT:
            playerPos.x++;
            break;
        default:
            // No movement in other cases
            break;
    }

    if (playerPos.x < 1)
        playerPos.x = mainGameMechsRef->getBoardSizeX() - 2;
    else if (playerPos.x >= mainGameMechsRef->getBoardSizeX() - 1)
        playerPos.x = 1;

    if (playerPos.y < 1)
        playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
    else if (playerPos.y >= mainGameMechsRef->getBoardSizeY() - 1)
        playerPos.y = 1;


    
    /*switch(myDir)
    {
        case UP:
            returnPos.setObjPos(playerPos.x, playerPos.y--, playerPos.symbol);
            
            if (playerPos.y <= 0)
            {
                playerPos.y = mainGameMechsRef->getBoardSizeY() - 2;
            }
            break;  
        case LEFT:
            returnPos.setObjPos(playerPos.x--, playerPos.y, playerPos.symbol);
            if (playerPos.x <= 0)
            {
                playerPos.x =  mainGameMechsRef->getBoardSizeX() - 2;
            }
            break;  
        case DOWN:
            returnPos.setObjPos(playerPos.x, playerPos.y++, playerPos.symbol);
            if (playerPos.y >= mainGameMechsRef->getBoardSizeY() - 1)
            {
                playerPos.y = 1;
            }
            break;  
        case RIGHT:
            returnPos.setObjPos(playerPos.x++, playerPos.y, playerPos.symbol);
            if (playerPos.x >= mainGameMechsRef->getBoardSizeX())
            {
                playerPos.x =  1;
            }
            break;    
        default:
            returnPos.setObjPos(playerPos.x, playerPos.y, playerPos.symbol);
            break;
            
        }*/
    
    

}


