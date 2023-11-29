#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13);
    myPlayer = new Player(myGM);

}

void GetInput(void)
{
    myGM->getInput();

}   

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->updatePlayerDir();

    myGM->clearInput();

}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);  

    MacUILib_printf("BoardSize: %d,%d, Player Pos: <%d, %d> with %c\n", myGM->getBoardSizeX(), myGM->getBoardSizeY(), tempPos.x, tempPos.y, tempPos.symbol);
    int i,j;
    for(i=0; i<myGM->getBoardSizeY(); i++) 
    {
        for(j=0; j<myGM->getBoardSizeX(); j++) 
        {
            if(i==0 || i==myGM->getBoardSizeY()-1) //prints border - vertical axis
            {
                MacUILib_printf("#");
            }
            else if (j==0||j==myGM->getBoardSizeX()-1) //prints border - horizontal axis
            {
                MacUILib_printf("#");
            }
            else if (i==tempPos.y && j==tempPos.x) // prints player at player position
            {
                printf("%c", tempPos.symbol);
            }
            else
            {
                printf(" "); //everything else remains empty
            }
        }
        printf("\n");
    }
    MacUILib_printf("Score: %d\n", myGM->getScore());
    if(myGM->getLoseFlagStatus() == true)
    {
        MacUILib_printf("You Lost!\n");
        myGM -> setExitTrue();
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    delete myGM;
    delete myPlayer;

    MacUILib_uninit();
}
