#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    for(int T=1;T<=t;T++){
        double r,h; cin>>r>>h;
        double x0,y0,z0; cin>>x0>>y0>>z0;
        double vx,vy,vz; cin>>vx>>vy>>vz;
        double a = vx * vx * h * h + vy * vy * h * h - vz * vz * r * r;
        double b = 2.0 * x0 * vx * h * h + 2.0 * y0 * vy * h * h + 2.0 * h * vz * r * r - 2.0 * z0 * vz * r * r;
        double c = x0 * x0 * h * h + y0 * y0 * h * h + 2.0 * z0 * h * r * r - r * r * h * h - z0 * z0 * r * r;
        double v1 = (-b + sqrt(b * b - 4.0 * a * c)) / 2.0 / a;
        double v2 = (-b - sqrt(b * b - 4.0 * a * c)) / 2.0 / a;
        if(v1 > v2) swap(v1,v2);
        if(v1 < 0) printf("Case %d: %.10lf\n",T,v2);
        else{
            if(z0 + vz * v1 >= 0 && z0 + vz * v1 <= h) printf("Case %d: %.10lf\n",T,v1);
            else printf("Case %d: %.10lf\n",T,v2);
        }
    }
    return 0;
}
