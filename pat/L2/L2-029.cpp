#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int primes[N],cnt;
bool st[N];

void get_primes(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]<=n/i;j++){
            st[primes[j]*i] = true;
            if(i%primes[j]==0)break;
        }
    }
}

int res[N];
bool del[N];

int get(int x){
    int sum = 0;
    while(x){
        sum += (x%10) * (x%10);
        x/=10;
    }
    return sum;
}

void f(int x,int y){
    map<int,int> mp;
    bool f = true;
    while(x!=1){
        if(mp[x]){
            f = false;break;
        }
        mp[x] = 1;
        x = get(x);
    }
    //for(auto &[a,b] : mp) cout<<a<<" ";cout<<"\n";
    if(f) {
        res[y] = mp.size();
        for(auto [a,b] : mp)
            if(a!=y)
                del[a] = true;
    }else{
        for(auto [a,b] : mp)
            del[a] = true;
    }
}

int main(){
    get_primes(10000);    
    int a,b;cin>>a>>b;
    for(int i=a;i<=b;i++) f(i,i);
    bool f = false;
    for(int i=a;i<=b;i++){
        if(!del[i] && res[i]){
            f = true;
            cout << i << " ";
            if(!st[i])
                cout << (res[i] << 1) << "\n";
            else 
                cout << res[i] << "\n";
        }
    }
    if(!f)puts("SAD");
    return 0;
}
