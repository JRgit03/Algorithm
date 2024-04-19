#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20;
int k;
int p[N];
int l[20][N];

// dfs(i,j,w) 
int dfs(int i,int j,int w){
	if(i == 1){
        if(w >= l[i][j]){
            p[2*j-1] = l[i][j];
            p[2*j] = w;
            return 1;
        }
        return 0;
    }
    if(w < l[i][j]) return 0;
    if(dfs(i-1,2*j-1,w) && dfs(i-1,2*j,l[i][j])) return 1;
    if(dfs(i-1,2*j-1,l[i][j]) && dfs(i-1,2*j,w)) return 1;
    return 0;
}

void solve(){
	cin>>k;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=pow(2,k-i);j++)
			cin>>l[i][j];	
	int w; cin>>w;
	if(dfs(k,1,w)){
		for(int i=1;i<=pow(2,k);i++) {
			if(i != 1) cout << " ";
			cout << p[i];
		}
	}else{
		cout << "No Solution" << "\n";
	}
}

int main(){
	solve();
	return 0;
}