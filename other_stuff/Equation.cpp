#include<bits/stdc++.h>
#include <iomanip>
using namespace std;
    main()
    {
        double a,b,c,x,x1,x2;
        cin>>a>>b>>c;
        x=(b*b)-4*a*c;
        if(a==0&&b==0&&c==0) {cout<<"-1";return 0;}
        if(a==0&&b==0) {cout<<"0";return 0;}
        if(x<0) {cout<<"0";return 0;}
        else if(a==0) {cout<<"1 ";printf("%lf",-c/b);return 0;}
        x=sqrt(x);
        x1=(-b-x)/(2*a);
        x2=(-b+x)/(2*a);
        if(x==0) {cout<<"1 ";printf("%lf",-b/(2*a));return 0;}
        cout<<"2 ";
        printf("%lf ",min(x1,x2));
        printf("%lf",max(x2,x1));
    }

