//
// Created by Macbook on 14.11.17.
//

#include <iostream>

using namespace std;

void swap( int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(&arr[++i],&arr[j]);
        }
    }

    swap(&arr[high], &arr[++i]);
    return i;
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

// Problem: we want to decrease number of recursive calls and auxiliary space

void optimizedQuickSort( int arr[], int low, int high)
{
    while (low < high)
    {
        int pi = partition(arr, low, high);

        if (pi - low < high - pi)
        {
            optimizedQuickSort(arr, low, pi - 1);
            low = pi + 1;
        }

        else
        {
            optimizedQuickSort(arr, pi + 1, high);
            high = pi - 1;
        }
    }
}

int main()
{
    int a[] = {7,8,6,5,9,3,4,5,1,2};
    int len = (sizeof(a)/sizeof(a[0]));
    optimizedQuickSort(a, 0, len - 1);

    printArray(a, 10);
}