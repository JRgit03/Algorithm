#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int max(int a,int b){return a > b ? a : b;}
int min(int a,int b){return a < b ? a : b;}

int n;
string s; int k;
double d;

void mul(vector<int> &v, int d){
    int t = 0;
    for(int i=0;i<v.size();i++) {
        t += v[i] * 2;
        v[i] = t % 10;
        t /= 10;
    }
    if(t != 0) v.push_back(t);
}

void solve(){
    cin>>n>>s;
    vector<int> v;
    for(int i=0;i<s.length();i++) {
       if(s[i] == '.') k = i;
       else v.push_back(s[i] - '0');
    }
    k = s.length() - (k + 1); 
    reverse(v.begin(), v.end());
    for(int i=0;i<n;i++){
       mul(v, 2);
    }
    // debug
//    for(int i=v.size()-1;i>=0;i--) cerr << v[i]; cerr << "\n";
//    cout << k << " " << v[k - 1] << "\n";
    if(v[k - 1] >= 5){ // add 1
        int t = 10;
        for(int i=k-1;i<v.size();i++){
            t += v[i];
            v[i] = t % 10;
            t /= 10;
        }
        if(t != 0) v.push_back(t);
        for(int i=v.size()-1;i>=k;i--) cout << v[i];
    }else{
        for(int i=v.size()-1;i>=k;i--) cout << v[i];
    }
}

signed main(){
    IOS;
    solve();
    return 0;
} 

// 2 3.14
