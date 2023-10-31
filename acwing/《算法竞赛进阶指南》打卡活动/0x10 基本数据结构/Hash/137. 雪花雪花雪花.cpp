#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Mod = 1e13 + 9 , P = 131;
int n=6,m;
int s[6];

int getmin(){
    int i=0,j=1,k=0,t;
    while(i<n&&j<n&&k<n){
        t=s[(i+k)%n]-s[(j+k)%n];
        if(!t)k++;
        else{
            if(t>0)i+=k+1;
            else j+=k+1;
            if(i==j)j++;
            k=0;
        }
    }
    return i<j?i:j;
}

set<int> mp;

signed main(){
    cin>>m;
    int f = 0;
    for(int i=0;i<m;i++){
        for(int i=0;i<6;i++) cin>>s[i];
        int h1,h2,h3,h4,h5,h6;
        h1 = h4 = 0; h2 = h5 = 1;
        int st = getmin();
        for(int i=0;i<6;i++) {
            h1 = (h1 * P + s[(i+st)%6]) % Mod;
            h2 = (h2 * s[(i+st)%6]) % Mod;
        }
        h3 = (h1 + h2) % Mod;
        f |= mp.count(h3);
        mp.insert(h3);
        reverse(s,s+6);
        st = getmin();
        for(int i=0;i<6;i++) {
            h4 = (h4 * P + s[(i+st)%6]) % Mod;
            h5 = (h5 * s[(i+st)%6]) % Mod;
        }
        h6 = (h4 + h5) % Mod;
        if(h3 != h6){ //防止翻转后是同一雪花
            f |= mp.count(h6);
            mp.insert(h6);
        }
    }
    cout << (f ? "Twin snowflakes found." : "No two snowflakes are alike.") << "\n";
    return 0;
}
