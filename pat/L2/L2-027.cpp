#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int n,G,K;
int sum;

struct Node{
    string name;
    int fs;
    
    bool operator < (const Node &t) const {
        if(fs!=t.fs) return fs > t.fs;
        return name < t.name;
    }
}v[N];

int main(){
    cin>>n>>G>>K;
    for(int i=1;i<=n;i++){
        cin>>v[i].name>>v[i].fs;
        if(v[i].fs >= G) sum += 50;
        else if(v[i].fs >= 60) sum += 20;
    }
    cout << sum << "\n";
    sort(v+1,v+1+n);
    int rk;
    for(int i=1;i<=n;i++){
        if(i==1){
            rk = 1;
            cout << rk << " " << v[i].name << " " << v[i].fs << "\n";
        }else{
            if(v[i].fs < v[i-1].fs) rk = i;
            if(rk > K)break;
            cout << rk << " " << v[i].name << " " << v[i].fs << "\n";
        }
    }
    return 0;
}
