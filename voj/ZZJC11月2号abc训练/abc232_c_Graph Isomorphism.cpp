/**
 * F
 * 图的同构
 * https://atcoder.jp/contests/abc232/tasks/abc232_c
 * 
 * 题意: 给你两个图 询问是否存在一个全排列使得B是A的同构图
 **/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 20;
int n,m;
PII g1[N*N];
int g2[N][N];

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v; u--,v--;
		g1[i] = {u,v};
	}	
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v; u--,v--;
		g2[u][v] = g2[v][u] = 1;
	}	
	vector<int> id(n);
	for(int i=0;i<n;i++) id[i] = i;
	do{
		int f = 1;
		for(int i=0;i<m;i++){
			int u = g1[i].first , v = g1[i].second; 
			f &= g2[id[u]][id[v]];
		}
		if(f){
			cout << "Yes" << "\n";
			return 0;
		}
	}while(next_permutation(id.begin(),id.end())); // O(8! * m)
	cout << "No" << "\n";
	return 0;
}

/**
 * 
 * 
 4 4
 1 2
 1 3
 1 4
 3 4
 1 3
 1 4
 2 3
 3 4
 Yes
 **/