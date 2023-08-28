#include <bits/stdc++.h>
using namespace std;
const int N = 505 , INF = 0x3f3f3f3f;
const double eps = 1e-10;
typedef pair<int,int> PII;
int n;
int dist[N],sex[N]; // 男1
bool vis[N];
vector<PII> h[N];

vector<int> male,fe;
double max1,max2;

void dij(int st){
    memset(dist,0x3f,sizeof dist);
    memset(vis,false,sizeof vis);
    dist[st] = 0;
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    heap.push({0,st});
    
    while(heap.size()){
        auto [distance,u] = heap.top(); heap.pop();
        if(vis[u])continue;
        vis[u] = true;
        
        for(auto [v,w] : h[u]){
            if(dist[v] > distance + w){
                dist[v] = distance + w;
                heap.push({dist[v],v});
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;cin>>c; sex[i] = (c=='M');
        int k,x,d;cin>>k;
        while(k--){
            scanf("%d:%d",&x,&d);
            h[i].push_back({x,d}); //别人对i的好感度！！！
        }
    }
    for(int i=1;i<=n;i++){
        dij(i);
        int maxd = -1;
        for(int j=1;j<=n;j++){
            //cout << i << " " << j << " " <<  (sex[i] ^ sex[j]) << "\n";
            //cout << dist[j] << "\n";
            if(dist[j]!=INF && i!=j && (sex[i] ^ sex[j])){
                //cout << i << "->" << j << " " << dist[j] << "\n";
                maxd = max(maxd , dist[j]);
            }
        } //cout << maxd << "\n";
        if(maxd==-1) continue; 
        double val = 1.0 / maxd; cout << "i: " << i << " val=" <<  val << "\n";
        if(sex[i]){
            if(val-max1>eps){
                max1 = val; 
                male.clear();
                male.push_back(i);
            }else if(val==max1){
                male.push_back(i);
            }
        }else{
            if(val-max2>eps){
                max2 = val; 
                fe.clear();
                fe.push_back(i);
            }else if(val==max2){
                fe.push_back(i);
            }
        }
    }
    sort(male.begin(),male.end());
    sort(fe.begin(),fe.end());
    
    if(fe.size()){
        cout << fe[0];
        for(int i=1;i<(int)fe.size();i++) cout << " " << fe[i];
        cout << "\n";
    }
    if(male.size()){
        cout << male[0];
        for(int i=1;i<(int)male.size();i++) cout << " " << male[i];
        cout << "\n";
    }
    return 0;
}
