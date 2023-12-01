#include <iostream> 
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
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
    srand(time(NULL));
    MacUILib_init();
    MacUILib_clearScreen();

    myGM = new GameMechs(26, 13);
    myPlayer = new Player(myGM);


    objPos tempPos(1, 1, 'o');
    myGM -> generateFood(tempPos);

    //objPos foodPos;
    //myPlayer->getPlayerPos(tempPos); 
    //myGM->getFoodPos(foodPos);

    /*if (foodPos.x == -1 && foodPos.y == -1){
        myGM -> generateFood(tempPos);
    }
    else if(tempPos.x == foodPos.x && tempPos.y == foodPos.y){
        myGM -> generateFood(tempPos);
        myGM -> incrementScore();
    }*/

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

    if(myPlayer->checkFoodConsumption()){
        myPlayer->increasePlayerLength();
    }


}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    bool drawn;

    objPosArrayList* playerBody = myPlayer->getPlayerPos();
    objPos tempPos;
    
    objPos foodPos;
    myGM->getFoodPos(foodPos);

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

            if(i==0 || i==myGM->getBoardSizeY()-1) //prints border - vertical axis
            {
                MacUILib_printf("#");
            }
            else if (j==0||j==myGM->getBoardSizeX()-1) //prints border - horizontal axis
            {
                MacUILib_printf("#");
            }
            else if (i == foodPos.y && j == foodPos.x)
            {
                printf("%c", foodPos.symbol);
            }
            else
            {
                printf(" "); //everything else remains empty
            }
        }
        printf("\n");
    }
    MacUILib_printf("Score: %d\n", myGM->getScore());
    MacUILib_printf("food x y: %d %d", foodPos.x, foodPos.y);
    MacUILib_printf("Player Positions:\n");
    for(int l = 0; l <playerBody->getSize(); l ++)
    {
        playerBody->getElement(tempPos, l);
        MacUILib_printf("<%d, %d> ", tempPos.x, tempPos.y);
    }

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
