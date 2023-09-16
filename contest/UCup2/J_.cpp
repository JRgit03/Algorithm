#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n,t;
int sx,sy,ex,ey;
int x[N],y[N];
vector<array<int,3>> path;

double get(int x1,int y1,int x2,int y2){
    int dx = x2 - x1 , dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    cin>>n>>t;
    cin>>sx>>sy>>ex>>ey;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    double ans = get(sx,sy,ex,ey);
    path.push_back({0,ex,ey});

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i == j){
                double cost = min(abs(sx-x[i]), abs(sy-y[i])) + t + min(abs(ex-x[i]), abs(ey-y[i]));
                if(cost < ans){
                    ans = cost;
                    path.clear();  
                    if(abs(sx-x[i]) < abs(sy-y[i])){
                        path.push_back({0,x[i],sy});
                    }else{
                        path.push_back({0,sx,y[i]});
                    }
                    if(abs(ex-x[i]) < abs(ey-y[i])){
                        path.push_back({i,x[i],ey});
                    }else{
                        path.push_back({i,ex,y[i]});
                    }
                    path.push_back({0,ex,ey});
                }
            }else{
                double cost = min(abs(sx-x[i]), abs(sy-y[i])) + t + t + min(abs(ex-x[j]), abs(ey-y[j]));
                if(cost < ans){
                    ans = cost;
                    path.clear();  
                    if(abs(sx-x[i]) < abs(sy-y[i])){
                        path.push_back({0,x[i],sy});
                    }else{
                        path.push_back({0,sx,y[i]});
                    }
                    path.push_back({i,x[i],y[j]});
                    if(abs(ex-x[j]) < abs(ey-y[j])){
                        path.push_back({j,x[j],ey});
                    }else{
                        path.push_back({j,ex,y[j]});
                    }
                    path.push_back({0,ex,ey});
                }        
            }
        }
    }
    printf("%.10lf\n",ans);
    cout << path.size() << "\n";
    for(auto &[a,b,c] : path)
        cout << a << " " << b << " " << c << "\n";
    return 0;
}