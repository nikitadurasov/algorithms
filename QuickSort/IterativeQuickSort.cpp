
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

void quickSortIterative (int arr[], int low, int high)
{
    // Create stack
    int stack[ high - low + 1 ];

    int top = -1;

    stack[ ++top ] = low;
    stack[ ++top ] = high;

    while ( top >= 0 )
    {
        high = stack[ top-- ];
        low = stack[ top-- ];

        int p = partition(arr, low, high);

        if (p - 1 > low)
        {
            stack[ ++top ] = low;
            stack[ ++top ] = p - 1;
        }

        if (p + 1 < high)
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = high;
        }
    }
}

int main()
{
    int a[] = {7,8,6,5,9,3,4,5,1,2};
    int len = (sizeof(a)/sizeof(a[0]));
    quickSortIterative(a, 0, len - 1);

    printArray(a, 10);
}