#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main(){
    IOS;
    int n;double line;cin>>n>>line;
    for(int i=0;i<n;i++){
        double x;cin>>x;
        if(x<line) printf("On Sale! %.1lf\n",x);
    }
    return 0;
}
