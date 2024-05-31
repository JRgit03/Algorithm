#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 5e2 + 10;
int n,k;


// AC 40/100
void solve1(){
    vector<int> vec;
    for(int i=1;i<=n;i++) vec.push_back(i);
    int ans = 0;
    do{
        int cnt = 0;
        for(int i=1;i<n-1;i++) {
            int f1 = (vec[i] > vec[i-1] && vec[i] > vec[i + 1]);
            int f2 = (vec[i] < vec[i-1] && vec[i] < vec[i + 1]);
            cnt += (f1 || f2);
        }
        if(cnt == k) ans += 1;
    }while(next_permutation(vec.begin(), vec.end()));
    cout << ans << "\n";
}

void solve2(){
    
}

void solve(){
    cin>>n>>k; k -= 1;
    if(n <= 10) solve1();
    else solve2();    
}

signed main(){
    IOS;
    solve();
    return 0;
}
