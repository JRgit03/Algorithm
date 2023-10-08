#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    int n,m; cin>>n>>m;
    vector<int> score(m),id(m);
    for(int i=0;i<m;i++) {
        id[i] = i; cin>>score[i]; 
    }   
    sort(id.begin(),id.end(),[&](int i,int j){
        return score[i] > score[j];
    });
    vector<int> df(n);
    vector<string> s(n);
    for(int i=0;i<n;i++){
        cin>>s[i]; 
        df[i] += i+1;
        for(int j=0;j<m;j++){
            if(s[i][j] == 'o'){
                df[i] += score[j];
            }
        }
    }
    int maxx = *max_element(df.begin(),df.end());
    for(int i=0;i<n;i++){
        int ans = 0 , k = 0;
        while(k<m && df[i] < maxx){
            if(s[i][id[k]] == 'x'){
                df[i] += score[id[k]];
                ans += 1;
            }
            k += 1;
        }
        cout << ans << "\n";
    }
}

int main(){
    IOS;
    solve();
    return 0;
}
