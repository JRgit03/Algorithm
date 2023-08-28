#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int q[N] , hh , tt=-1;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(i==1){
            q[++tt] = x;
        }else{
            int l = 0 , r = tt;
            while(l < r){
                int mid = l + r >> 1;
                if(q[mid] >= x) r = mid;
                else l = mid + 1;
            }

            if(q[r] < x) q[++tt] = x;
            else q[r] = x;
        }
    }
    cout << tt + 1 << "\n";
	return 0;
}