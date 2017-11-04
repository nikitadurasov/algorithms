//
// Created by Macbook on 04.11.17.
//

//problem from http://www.spoj.com/problems/AGGRCOW/

#include <iostream>
#include <algorithm>

using namespace std;

int N, C;

int func(int num,int array[])
{
    int cows=1,pos=array[0];
    for (int i=1; i<N; i++)
    {
        if (array[i]-pos>=num)
        {
            pos=array[i];
            cows++;
            if (cows==C)
                return 1;
        }
    }
    return 0;
}

int bs(int array[])
{
    int ini=0,last=array[N-1],max=-1;
    while (last>ini)
    {
        int mid=(ini+last)/2;
        if (func(mid,array)==1)
        {
            if (mid>max)
                max=mid;
            ini=mid+1;
        }
        else
            last=mid;
    }
    return max;
}


int run_test()
{
    int N, C;
    cin >> N;
    cin >> C;

    int stalls[N];
    for (int i = 0; i < N; i++)
    {
        int x_i;
        cin >> x_i;
        stalls[i] = x_i;
    }

    sort(stalls, stalls + N);

    int k=bs(stalls);

    return k;
}


int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &N, &C);
        int array[N];
        for (int i = 0; i < N; i++)
            scanf("%d", &array[i]);
        sort(array, array + N);
        int k = bs(array);
        printf("%d\n", k);
    }
    return 0;
}