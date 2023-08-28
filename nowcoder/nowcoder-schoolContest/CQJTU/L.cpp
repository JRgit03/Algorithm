#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 22;
int a[N],b[N];
int wina,winb;

void solve(){
    int i=1;
    for(;i<=5;i++){
        wina += (a[i]==1);
        if(wina+(5-i)<winb || winb+(5-i)+1<wina){
            cout << i << "\n";
            cout << wina << ":" << winb << "\n";
            return;
        }
        winb += (b[i]==1);
        if(wina+(5-i)<winb || winb+(5-i)<wina){
            cout << i << "\n";
            cout << wina << ":" << winb << "\n";
            return;
        }
    }
    if(wina!=winb){
        cout << 5 << "\n";
        cout << wina << ":" << winb << "\n";
        return;
    }
    for(;;i++){
        wina += (a[i]==1);
        winb += (b[i]==1);
        if(a[i]^b[i]){
            cout << i << "\n";
            cout << wina << ":" << winb << "\n";
            return;
        }
    }
}

int main(){
    IOS;
    for(int i=1;i<=20;i++)cin>>a[i];
    for(int i=1;i<=20;i++)cin>>b[i];
    solve();
    return 0;
}
