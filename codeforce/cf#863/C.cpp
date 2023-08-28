#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

void solve(){
	int n;cin>>n;n--;
    vector<int> b(n+1),a(n+1);
    int minn = 2e9 , k = 0;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;b[i]=x;
        if(x < minn){
            minn = x;
            k = i;
        }
    }
    //cout << k << " " << minn << "\n\n";
    a[k-1] = minn , a[k] = minn;
    for(int i=k-1;i>=1;i--){
        //cout << a[i] << " " << b[i] << "\n";
        if(a[i] < b[i]) a[i-1] = b[i];
        else if(a[i]==b[i]){
            if(i-1>=1){
                if(b[i-1] > b[i]) a[i-1] = b[i];
                else a[i-1] = b[i-1];
            }else{
                a[i-1] = b[i];
            }
        }
    }
    for(int i=k+1;i<=n;i++){
        //cout << a[i-1] << " " << b[i] << "\n";
        if(a[i-1] < b[i]) a[i] = b[i];
        else if(a[i-1]==b[i]){
            if(i+1<=n){
                if(b[i+1] > b[i]) a[i] = b[i];
                else a[i] = b[i+1];
            }else{
                a[i] = b[i];
            }
        }
    }

    for(int i=0;i<=n;i++) cout << a[i] << " \n"[i==n];
}

int main(){
	IOS;
	int t;cin>>t;
	while(t--)solve();
	return 0;
}