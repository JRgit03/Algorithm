#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10;
int n,m;
char s[N];
char t[N];

int find(){
    int j = 1 , ans = 0;
    for(int i=1;i<=n;i++){
        if(s[i]==t[j]) j++;
        else j = 1;
        if(j > m){
            ans++;
            j = 1;
        }
    }
    return ans;
}

int main(){
    IOS;
    cin>>n>>m;
    cin>>s+1>>t+1;
    cout << find() << "\n";
    return 0;
}
