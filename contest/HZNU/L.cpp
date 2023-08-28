#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,d;cin>>m>>d;
    vector<int> a(6),b(6);
    for(int i=1;i<=5;i++) cin>>a[i]; //price
    for(int i=1;i<=5;i++) cin>>b[i]; //value
    
    double res = 0.0;

    for(int k=1;k<(1<<5);k++){
        double vals = 0.0 , prices = 0.0;
        for(int i=0;i<5;i++){
            if((k>>i) & 1){
                vals += b[i+1];
                prices += a[i+1];
            }
        }
        if(prices >= m) prices -= d;

        if(prices!=0 && vals / prices > res){
            res = vals / prices;
        }
    }
    printf("%.2lf\n",res);
    return 0;
}
