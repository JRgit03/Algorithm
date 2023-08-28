#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 210 , INF = 0x3f3f3f3f;
int n;
int dist[26][N][N];
int main(){
    IOS;
    int n;cin>>n;
    for(int c=0;c<26;c++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(i==j)dist[c][i][j]=0;
                else dist[c][i][j]=INF;
            }
    int u,v;
    while(cin>>u>>v){
        if(!u && !v)break;
        string s;cin>>s;for(auto c : s)dist[c-'a'][u][v]=1;
    }

    for(int c=0;c<26;c++)
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)  
                for(int j=1;j<=n;j++){
                    dist[c][i][j] = min(dist[c][i][j] , dist[c][i][k] + dist[c][k][j]);
                }

    while(cin>>u>>v){
        if(!u && !v)break;
        string res = "";
        for(int i=0;i<26;i++)
            if(dist[i][u][v]!=0 && dist[i][u][v]!=INF) res = res + (char)(i+'a');
        if(res=="")cout<<"-"<<"\n";
        else cout<<res<<"\n";
    }
    return 0;
}
