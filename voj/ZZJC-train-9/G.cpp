#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const double eps = 1e-8;
int n;
double sx,sy,tx,ty;
double v1,v2;
double px[N],py[N];
bool st[N];
double g[N][N];
double dist[N];

double get(int i,int j){ // i -> j
    double d = sqrt((py[j] - py[i])*(py[j] - py[i]) + (px[j] - px[i])*(px[j] - px[i]));
    if(i==1) return d*1.0/v1;
    else{   
        if(v2*3.0>=d) return d/v2;
        return (d-v2*3.0)/v1+3;
    }
}

double dij(){
    for(int i=1;i<=n+2;i++) dist[i] = 3e9;
    dist[1] = 0;

    for(int i=0;i<n+1;i++){
        int t = -1;
        for(int j=1;j<=n+2;j++)
            if(!st[j] && (t==-1 || dist[t] > dist[j]))
                t = j;
            
        for(int j=1;j<=n+2;j++)
            dist[j] = min(dist[j],dist[t]+g[t][j]);
        
        st[t] = true;
    }
    
    return dist[n+2];
}

int main(){
    
    cin>>n;
    for(int i=2;i<=n+1;i++) cin>>px[i]>>py[i];
    cin>>sx>>sy>>tx>>ty>>v1>>v2;
    px[1] = sx , py[1] = sy , px[n+2] = tx , py[n+2] = ty;

    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=n+2;j++){
            if(i==j) g[i][j] = 0;
            else g[i][j] = get(i,j);
        }

   printf("%.12lf\n",dij());

    return 0;
}
