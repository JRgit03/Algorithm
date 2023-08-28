#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;

struct Node{
    int st,ed;

    bool operator < (const Node &t) const {
        return st < t.st;
    }
}vec[N];

void change(int l,int r){
    int h,m,s,hh,mm,ss;
    h = l / 3600 , m = l % 3600 / 60 , s = l % 60;
    hh = r / 3600 , mm = r % 3600 / 60 , ss = r % 60;
    printf("%02d:%02d:%02d - %02d:%02d:%02d\n",h,m,s,hh,mm,ss);
}

int main(){
    cin>>n; vec[0] = {0,0};vec[n+1] = {24*3600-1,24*3600-1};
    for(int i=1;i<=n;i++){
        int a,b,h,m,s;
        scanf("%02d:%02d:%02d",&h,&m,&s); a = h * 3600 + m * 60 + s;
        char c;cin>>c;
        scanf("%02d:%02d:%02d",&h,&m,&s); b = h * 3600 + m * 60 + s;
        vec[i] = {a,b};
    }
    sort(vec+1,vec+1+n);
    
    for(int i=1;i<=n+1;i++) {
        auto [a,b] = vec[i-1];
        auto [c,d] = vec[i];
        if(b!=c) change(b,c);
    }
    return 0;
}
