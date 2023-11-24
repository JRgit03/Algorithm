#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int maxn = 1e4 + 10;
int s[maxn];

int main(){
    IOS;
    for(int i=1;i<=10000;i++)
        for(int j=i;j<=10000;j+=i)
            s[j] += 1;
    int maxx = -1;
    for(int i=1;i<=10000;i++) maxx = max(maxx,s[i]);
    cout << maxx << "\n";
    cout << (int)pow(maxx,4) << "\n"; //16-777-216 = 1e7 + 1e6 1s = 1e8
    return 0;
}
