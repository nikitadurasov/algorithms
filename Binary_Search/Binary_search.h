//
// Created by Macbook on 04.11.17.
//

#ifndef CODEFORCES_BINARY_SEARCH_H
#define CODEFORCES_BINARY_SEARCH_H

int binarySearchRec(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l)/2;

        if (arr[mid] == x) return mid;

        if (arr[mid] > x) return binarySearchRec(arr, l, mid - 1, x);

        return binarySearchRec(arr, mid+1, r, x);
    }

    return -1;
}

int binarySearchIter(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] > x)
            r = m - 1;

        else
            l = m + 1;

    }

    return -1;
}

#endif //CODEFORCES_BINARY_SEARCH_H
