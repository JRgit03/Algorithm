#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
typedef long long ll;

int main(){
    IOS;
    int n,m;
    cin>>n>>m;
    int a=min(n,m);
    int b=max(n,m);
    int re,yu;
    re=(b-1)/(a-1);
    yu=(b-1)%(a-1);
    if(re%2==0){
        if(yu==0){
            cout<<re/2*(a+a-2)+a;
        }
        else cout<<re/2*(a+a-2)+a+1;
    }
    else {
        if(yu==0){
            cout<<(re+1)/2*(a-2)+re/2*a+a;
        }
        else cout<<(re+1)/2*(a-2)+re/2*a+a+1;
    }
    return 0;
}
