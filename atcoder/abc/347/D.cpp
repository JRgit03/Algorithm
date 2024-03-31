#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> get(int x){
    vector<int> res;
    for(int i=0;i<60;i++){
        if((x >> i) & 1) res.push_back(i);
    }
    return res;
}

int calc(vector<int> &v){
    int res = 0;
    for(int i=0;i<60;i++) 
        if(v[i] == 1)
            res |= (1LL << i);
    return res;
}

void solve(){
    int a,b,c; cin>>a>>b>>c;
    vector<int> pos = get(c); // c值1的位置
    for(int i=0;i<=a;i++){ // 枚举a放i个1在c上
        int sz1 = i, sz2 = pos.size() - i;
        if(sz2 > b || sz2 < 0) continue;
        if(a - i != b - sz2) continue;
        if(a - i > 60 - pos.size()) continue;
        vector<int> va(60), vb(60);
        for(int j=0;j<pos.size();j++){
            if(j < i) va[pos[j]] = 1;
            else vb[pos[j]] = 1;
        }
        // for(int i=0;i<10;i++) cout << va[i] << " "; cout << "\n";
        // for(int i=0;i<10;i++) cout << vb[i] << " "; cout << "\n";
        int ne = a - i;
        for(int j=0;j<60;j++) {
            if(ne > 0 && va[j] == 0 && vb[j] == 0){
                va[j] = vb[j] = 1;
                ne -= 1;
            }
        }
        // cout << sz1 << " " << sz2 << "\n";
        cout << calc(va) << " " << calc(vb) << "\n";
        return;
    }
    cout << -1 << "\n";
    return;
}

signed main(){
    solve();
    return 0;
}
