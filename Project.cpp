#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "GameMechs.h"
#include "Player.h"
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;
Food* myFoodList;


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
    srand(time(NULL));
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13);
    myFoodList = new Food(myGM);
    myPlayer = new Player(myGM, myFoodList);

}

void GetInput(void)
{
    myGM->getInput();

}   

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    myGM->clearInput();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    if(myGM->getLoseFlagStatus() == true)
    {
        MacUILib_printf("You Lost!\n");
        myGM -> setExitTrue();
    }

    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempPos;

    int i,j;
    for(i=0; i<myGM->getBoardSizeY(); i++) 
    {
        for(j=0; j<myGM->getBoardSizeX(); j++) 
        {
            drawn = false;
            for(int k = 0; k < playerBody->getSize(); k++)
            {
                playerBody->getElement(tempPos, k);
                if(tempPos.x == j && tempPos.y == i)
                {
                    MacUILib_printf("%c", tempPos.symbol);
                    drawn = true;
                    break;
                }
            }
            if(drawn) continue;

            bool used = false;
            for(int m = 0; m < 3; m++){
                objPos foodPos;
                myFoodList->getFoodPos(foodPos, m);
                if(foodPos.x == j && foodPos.y == i){
                    MacUILib_printf("%c", foodPos.symbol);
                    used = true;

                    break;
                }
            }

            if(used) continue;

            if(i==0 || i==myGM->getBoardSizeY()-1) //prints border - vertical axis
            {
                MacUILib_printf("#");
            }
            else if (j==0||j==myGM->getBoardSizeX()-1) //prints border - horizontal axis
            {
                MacUILib_printf("#");
            }
            else
            {
                printf(" "); //everything else remains empty
            }
        }
        printf("\n");
    }
    MacUILib_printf("Score: %d\n", myGM->getScore());
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
