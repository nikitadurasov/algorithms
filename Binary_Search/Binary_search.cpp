//
// Created by Macbook on 04.11.17.
//
#include <iostream>
#include "Binary_search.h"

using namespace std;

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);

    int x = 10;

    int result = binarySearchRec(arr, 0, n-1, x);

    (result == -1)? cout << "Element is not in array" << endl
                  : cout << "Element is in position " << result << endl;

    result = binarySearchIter(arr, 0, n-1, x);

    (result == -1)? cout << "Element is not in array"
                  : cout << "Element is in position " << result;
}