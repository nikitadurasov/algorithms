#include <iostream>

using namespace std;

int main() {
    int x, n, t, sum=0;
    cin >> n >> x;
    int arr[101] = {0};

    if(x<0 || x>100) {return 0;}

    for(int i = 0; i < n; i++) {
        cin >> t;
        arr[t] = 1;
    }

    for(int i=0; i<x; i++) {
        if(!arr[i]) {sum++;}
    }

    if(arr[x] != 0) {sum++;}

    cout << sum;
};

