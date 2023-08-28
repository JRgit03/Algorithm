#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main(){
    IOS;
    vector<int> time(25);
    for(int i=0;i<=23;i++) cin>>time[i];
    int x;while(cin>>x){
        if(x<0 || x>23)break;
        if(time[x]>50) cout << time[x] << " " << "Yes" << "\n";
        else cout << time[x] << " " << "No" << "\n";
    }
    return 0;
}
