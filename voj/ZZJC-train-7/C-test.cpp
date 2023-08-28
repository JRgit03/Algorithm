#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> vec(N);

void init(){
    int cnt = 0;
    for(int i=1;cnt<=100000;i++){
        int st = 20 - i + 1 ; int pre = cnt;
        vec[++cnt] = st;
        for(int j=pre;j>0;j--){
            if(cnt+1>100000)return;
            vec[++cnt] = vec[j];
        }
    }
}

int main(){
    init();
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        if(i==1)cout<<vec[i];
        else cout<<" "<<vec[i];
    }
    return 0;
}
