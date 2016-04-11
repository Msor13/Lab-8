#include <iostream>
#include <sstream>
#include "QS.h"

void QS::sortAll()
{
    Sort_All_Recursive(0, size-1);
}

void QS::Sort_All_Recursive(int left, int right)
{
    if(left == right)
    {
        return;
    }
    else if (left == right + 1 || left == right + 2)
    {
        medianOfThree(left, right);
        return;
    }
    else
    {
        int middle = medianOfThree(left, right);
        middle = partition(left,right, middle);
        Sort_All_Recursive(left, middle-1);
        Sort_All_Recursive(middle+1,right);
    }
}

int QS::medianOfThree(int left, int right)
{
    int middle;
    
    if (array == NULL || left < 0 || right > capacity - 1 || left >= right)
    {
        middle = -1;
    }
    else
    {
        middle =  (left + right) / 2;
        while (array[left] > array[middle] || array[middle] > array[right] || array[left] > array[right])
        {
            if(array[left]>array[middle])
            {
                 swap(left,middle);
            }
            else if(array[middle]>array[right])
            {
                swap(middle,right);
            }
            else
            {
                swap(left,right);
            }
        }
    }
    
    return middle;
}

void QS::swap(int left, int right)
{
    int temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}

int QS::partition(int left, int right, int pivotIndex)
{
    int r_bound, l_bound;

    if( array == NULL || left < 0 || right > size - 1 || pivotIndex < left || pivotIndex > right || left >= right)
    {
        
    }
    else
    {
        r_bound = left + 1;
        l_bound = right - 1;
        
        swap(pivotIndex, left);
        while(r_bound < l_bound)
        {
            while(array[r_bound] <= array[left] && r_bound <= right)
            {
                r_bound++;
            }
            while(array[l_bound] > array[left] && l_bound >= left)
            {
                l_bound--;
            }
            if(l_bound>r_bound)
            {
                swap(r_bound, l_bound);
            }
        }
        swap(left, l_bound);
    }
    
    return l_bound;
}


string QS::getArray()
{
    stringstream array_string;
    if(array == NULL)
    {
        array_string << "";
    }
    else
    {
        for(int i = 0; i < size - 1; i++)
        {
            array_string << array[i] << ",";
        }
        array_string << array[size - 1];
    }
    
    return array_string.str();
}


int QS::getSize()
{
    return size;
}

void QS::addToArray(int value)
{
    if(array != NULL && size > capacity)
    {
        array[size] = value;
        size++;
    }
}

bool QS::createArray(int capacity)
{
    bool test;
    if ( capacity < 0)
    {
        test = false;
    }
    else
    {
        if(array != NULL)
        {
            clear();
        }
        array = new int[capacity];
        this->capacity = capacity;
        test = true;
    }
    return test;
}

void QS::clear()
{
    if(array != NULL)
    {
        delete[] array;
        array = NULL;
        size = 0;
        capacity = 0;
    }
}








