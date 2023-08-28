#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10;
int sum[N];
unordered_map<int,int> mp;
int main(){
    IOS;
    for(int i=1;i<=100000;i++)   
        for(int j=i;j<=100000;j+=i)
            sum[j]++;
    for(int i=1;i<=100000;i++)
        if(!mp[sum[i]]){
            mp[sum[i]] = i;
        }
    int n;cin>>n;cout<<mp[n]<<"\n";
    return 0;
}
