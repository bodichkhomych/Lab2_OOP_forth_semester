#include "sorting.h"
#include<iostream>


using std::swap;

Sorting::Sorting()
{

}



void Sorting::BubbleSort(int *numbers,int size)
{
    for (int i=0;i<size-1;i++)
    {
        bool was_swap=0;
        for (int j=0;j<size-i-1;j++)
        {
            if (numbers[j]>numbers[j+1])
            {
                emit nextIteration(j,j+1,1);
                swap(numbers[j],numbers[j+1]);
                was_swap=1;
            }
            else
            {
                emit nextIteration(j,j+1,0);
            }
        }
        if (!was_swap)
        {
            break;
        }
    }
    emit nextIteration(-1,-1,0);
}

void Sorting::BogoSort(int *arr, int size)
{
    while (!isSorted(arr,size))
    {
        arr=shuffle(arr,size);
        emit nextIteration(arr);
    }
}

bool Sorting::isSorted(int *arr, int size)
{
    for (int i=1;i<size;i++)
        if (arr[i]<arr[i-1]) return false;
    return true;
}

int *Sorting::shuffle(int *arr, int size)
{
    for (int i=0; i <size; ++i)
    {
        int rand = QRandomGenerator::global()->bounded(0,size);
        swap(arr[i], arr[rand]);
    }
    return arr;
}



