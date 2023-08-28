#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 1e5 + 10;
int n;
char p[N];
int ne[N];

int main(){
    IOS;
    cin>>n;
    cin>>p+1;

    for(int i=2,j=0;i<=n;i++){
        while(j && p[i]!=p[j+1]) {
            j = ne[j];
        }
        if(p[i] == p[j+1]) j++;
        ne[i] = j;
    }

    //for(int i=1;i<=n;i++) cout << ne[i] << " \n"[i==n];

    for(int i=1;i<=n;i++){
        if(ne[i]>0){
            cout << "Wrong Answer" << "\n";return 0;
        }
    }
    cout << "Correct" << "\n";return 0;
}
