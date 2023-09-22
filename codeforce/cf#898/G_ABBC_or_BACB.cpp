#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

void solve(){
    string s; cin>>s;
    int n = s.length(); s = "$" + s;
    vector<int> vec; // num 0-point
    
    int cnta = 0 , cntb = 0;
    int minx = 2e9 , sum = 0;
    int sza = 0, szb = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == 'A'){
            cnta += 1;
            cntb = 0;
        }else if(s[i] == 'B'){
            if(cnta > 0){
                vec.push_back(cnta);  
                minx = min(minx,cnta);
                sum += cnta;
                sza += 1;
                cnta = 0;
            }
            cntb += 1;
            if(cntb <= 2){
                vec.push_back(0);
                szb += 1;
            }
        }
    }
    if(cnta > 0){
    	vec.push_back(cnta);  
        minx = min(minx,cnta);
        sum += cnta;
        sza += 1;
    }

    //for(auto &x : vec) cout << x << "\n"; cout << "\n";

    int m = vec.size();
    if(m > 2) {
        cout << (szb >= sza ? sum : sum - minx) << "\n";
    }else{
        if(m <= 1) cout << 0 << "\n";
        else cout << max(vec[0],vec[1]) << "\n";
    }
}

int main(){
    IOS;
    int t;cin>>t;
    while(t--)solve();
    return 0;
}
