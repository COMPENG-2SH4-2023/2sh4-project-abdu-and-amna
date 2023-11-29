#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    sizeArray = 200;
    sizeList = 0;

    aList = new objPos[sizeArray];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize()
{
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    for(int i = sizeList; i > 0; i--)
    {
        aList[i] = aList[i-1]
    }
    aList[0] = thisPos;

    sizeList++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[sizeList++] = thisPos
}

void objPosArrayList::removeHead()
{
    for(int i = 0; i < sizeList-1; i++)
    {
        aList[i] = aList[i+1];
    }
    sizeList--;
}

void objPosArrayList::removeTail()
{
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos)
{

}

void objPosArrayList::getTailElement(objPos &returnPos)
{
     
}

void objPosArrayList::getElement(objPos &returnPos, int index)
{

}