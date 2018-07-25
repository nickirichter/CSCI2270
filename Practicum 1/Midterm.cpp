//Midterm Programming Questions

#include <iostream>
using namespace std;

int *makeNewArray(int inputArray[], int arraySize, int compareNum)
{
    int *newArray = new int[arraySize];
    int cur = 0;
    for(int i=0; i<arraySize; i++)
    {
        if(inputArray[i]>compareNum)
        {
            newArray[cur]=array[i];
            cur++;
        }
    }
    return newArray;
}
