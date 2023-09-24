#include <bits/stdc++.h>
using namespace std;

int main(){
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int n,k; cin>>n>>k;
        if(n<=4){
            if(n+1 == k){
                cout << 0 << "\n";
            }else{
                cout << -1 << "\n";
            }
        }else{
            int minx = n+1;
            int maxx = minx + ((n-3)/4+1)*4;
            cout << minx << " " << maxx << "\n";
            if(k < minx || k > maxx || ((maxx - k) % 2)){
                cout << -1 << "\n";
            }else{
                if( (maxx - k) / 2 > (n-2+2-1)/2 ){
                    cout << -1 << "\n";
                }else{
                    cout << (n-2+2-1)/2*2 - (maxx - k) / 2 << "\n";
                }
            }
        }
    }
        
    return 0;
}
