#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

const int N = 1e6 + 10;
string a[10] = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
string b[12] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};

void solve(){
    int t = 2020, i = 6, j = 0;
    int y; cin>>y;
    while(t != y){
        i = (i + (y > t ? 1 : -1) + 10) % 10;
        j = (j + (y > t ? 1 : -1) + 12) % 12;
        t = t + (y > t ? 1 : -1);
    }
    string ans = a[i] + b[j];
    cout << ans << "\n";
}

signed main(){
    IOS;
    solve();
    return 0;
}
