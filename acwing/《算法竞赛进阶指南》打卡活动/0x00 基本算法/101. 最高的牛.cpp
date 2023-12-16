#include <bits/stdc++.h>
using namespace std;
int n,p,h,m;
int b[5050];
set<pair<int,int>> st;
int main(){
    cin>>n>>p>>h>>m;
    while(m--){
        int A,B; cin>>A>>B; if(A > B) swap(A,B);
        if(!st.count({A,B})){
            st.insert({A,B});
            b[A+1] -= 1; b[B] += 1;
        }
    }
    for(int i=1;i<=n;i++) b[i] += b[i-1];
    for(int i=1;i<=n;i++) cout << b[i] + h << "\n"; 
    return 0;
}
