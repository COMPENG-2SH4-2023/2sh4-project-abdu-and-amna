#include "Food.h"
#include "MacUILib.h"

Food::Food(GameMechs* thisGMRef){
    GMref = thisGMRef;
    foodBucket = new objPosArrayList();
}

Food::~Food(){
    //delete foodBucket;
}

void Food::generateFood(objPosArrayList* playerBody)
{
    //MacUILib_printf("player body: %d", playerBody->getSize());
    //MacUILib_printf("test");
    for(int i = 0; i < 3; i++){
        //MacUILib_printf("%d\n", i);
        int flag = 0;
        bool overlap = false;
        while (flag == 0) {
            //MacUILib_printf("%d\n", flag);
            int x = rand() % (GMref->getBoardSizeX() - 2) + 1;
            //int x = GMref->getBoardSizeX();
            //MacUILib_printf("coords: %d \n", x);
            int y = rand() % (GMref->getBoardSizeY() - 2) + 1;
            //MacUILib_printf("coords: %d %d", x, y);

            for (int k = 0; k < playerBody->getSize(); k++)
            {
                //MacUILib_printf("%d", k);
                objPos tempPos;
                playerBody->getElement(tempPos, k);
                if (x == tempPos.x && y == tempPos.y)
                {
                    overlap = true;
                    break;
                }
                for(int j = 0; j < i; j++){
                    objPos foodElement;
                    foodBucket->getElement(foodElement, j);
                    if(x == foodElement.x && y == foodElement.y){
                        overlap = true;
                        break;
                    }
                }
            }

            if (!overlap)
            {
                char symbol;
                if (i==0){
                    symbol = '$';
                }
                else{
                    symbol = (i==1) ? 'o' : '.';
                }
                foodPos.setObjPos(x, y, symbol);
                foodBucket->insertHead(foodPos);
                flag = 1;
            }
        }
    } 
}
    

void Food::getFoodPos(objPos &returnPos, int num)
{
    foodBucket->getElement(foodPos, num);
    returnPos.setObjPos(foodPos.x, foodPos.y, foodPos.symbol);
}

