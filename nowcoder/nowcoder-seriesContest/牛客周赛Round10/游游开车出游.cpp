#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
double l,r;
int x,y,c;

double f(double k){
    return k + y / (k * x + c);
}

int main(){
    cin>>c>>x>>y;
    l = 0 , r = 2e9;
    while(r-l>=eps){
        double k = (r-l) / 3.0;
        double lmid = l + k , rmid = r - k;
        if(f(lmid) >= f(rmid)) l = lmid;
        else r = rmid;
    }
    printf("%.10lf\n",f(r));
    return 0;
}
