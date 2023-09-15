#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n;
string s1,s2;
int a[N];
int g[N][N],vis[N];
int d[N];
int path[N];

/**

*/
void dfs(int st,int cnt){
	// cout << cnt << " " << st << "\n";
	path[cnt] = st;
	
	if(cnt == n){
		for(int i=1;i<=n;i++) printf("%c",path[i] + 'a'); printf("\n"); return;
 	}
 	
 	vis[st] = 1;
 	for(int i=0;i<n;i++)
 		if(!vis[a[i]] && g[st][a[i]])
 			d[a[i]]--;
 	
 	for(int i=0;i<n;i++)
 		if(!vis[a[i]] && !d[a[i]])
 			dfs(a[i],cnt+1);
 			
	for(int i=0;i<n;i++)
 		if(!vis[a[i]] && g[st][a[i]])
 			d[a[i]]++;
 	vis[st] = 0;
}

int main(){
    int hasOut = 0;
	while(getline(cin,s1)){
//		cout << "debug: " << s1 << "\n";
		memset(g,0,sizeof g);
		memset(vis,0,sizeof vis);
		memset(d,0,sizeof d);	
		if(s1 == "")break;
        if(hasOut) printf("\n");
		stringstream ss1(s1);
		vector<char> vec;
		char c; while(ss1 >> c) vec.push_back(c);
		sort(vec.begin(),vec.end());
		n = vec.size();
		for(int i=0;i<n;i++) a[i] = vec[i] - 'a';
		// for(int i=0;i<n;i++) cout << a[i] << "\n";
		
		getline(cin,s2);
//		cout << "debug: " << s2 << "\n";
		stringstream ss2(s2);
		char u,v; while(ss2 >> u >> v) g[u - 'a'][v - 'a'] = 1 , d[v-'a']++;
		
		for(int i=0;i<n;i++)
			if(!d[a[i]]) 
				dfs(a[i],1);
        
        hasOut = 1;
	}
	return 0;
}