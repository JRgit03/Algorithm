#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b) { return (a > b ? a : b);}
int min(int a,int b) { return (a < b ? a : b);}

const int N = 1e6 + 10;

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}

void solve(){
    map<array<int,3>,int> mp;
    int n = 20, m = 21;
    for(int x1=0;x1<n;x1++){
        for(int y1=0;y1<m;y1++){
            for(int x2=0;x2<n;x2++){
                for(int y2=0;y2<m;y2++){
                    if(x1 == x2) continue;
                    if(y1 == y2) continue;
                    int dx = x2 - x1, dy = y2 - y1, x = gcd(dx, dy);
                    dx /= x, dy /= x;
                    mp[{dy,dx,-x1*dy+y1*dx}] += 1;
                }
            }
        }
    }
    cout << mp.size() + n + m << "\n";
}

signed main(){
    IOS; solve();
    return 0;
}

