#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);

double f(double x){
    return sqrt((0.75-sqrt(13.0/8.0)*cos(x))*(0.75-sqrt(13.0/8.0)*cos(x)) + (1.0+sqrt(13.0/8.0)*sin(x))*(1.0+sqrt(13.0/8.0)*sin(x)));
}

int main(){
    double res = 0.0;
    for(double i=acos(5.0/13.0);i<=acos(5.0/13.0)+PI;i+=0.000001){
        res = max(res , f(i));
    }
    printf("%.10lf\n",res); 
    return 0;
}
