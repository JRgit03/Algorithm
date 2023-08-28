#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main(){
    IOS;
    int sum1=0,sum2=0;
    for(int i=0;i<5;i++){
        int x;cin>>x;sum1 += x;
    }
    for(int i=0;i<5;i++){
        int x;cin>>x;sum2 += x;
    }
    cout << (sum2 <= sum1 ? "Blue" : "Red") << "\n";
    return 0;
}
