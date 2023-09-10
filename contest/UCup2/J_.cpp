#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int n,t;
int sx,sy,ex,ey;
double ans;
pair<int,int> point[N];

double get(int x1,int y1,int x2,int y2){
    int dx = x1 - x2 , dy = y1 - y2;
    //cout << dx << " " << dy << "\n";
    return sqrt(dx*dx + dy*dy);
}

void solve(){
    cin>>n>>t;
    cin>>sx>>sy>>ex>>ey;
    for(int i=1;i<=n;i++) {
        int x,y; cin>>x>>y;
        point[i] = {x,y};
    }

    vector<tuple<int,int,int>> path; 
    ans = get(sx,sy,ex,ey); //cout << "init: " << ans << "\n";
    path.push_back({0,ex,ey});

    int select3 = -1, select4 = -1;
    int x3,y3,x4,y4;
    int dist3 = INT_MAX , dist4 = INT_MAX;
    
    for(int i=1;i<=n;i++){
        auto [x,y] = point[i];

        if(abs(x-sx) < abs(y-sy)){
            if(abs(x-sx) < dist3){
                dist3 = abs(x-sx);
                x3 = x , y3 = sy;
                select3 = i;
            }
        }else{
            if(abs(y-sy) < dist3){
                dist3 = abs(y-sy);
                x3 = sx , y3 = y;
                select3 = i;
            }
        }
        if(abs(x-ex) < abs(y-ey)){
            if(abs(x-ex) < dist4){
                dist4 = abs(x-ex);
                x4 = x , y4 = ey;
                select4 = i;
            }
        }else{
            if(abs(y-ey) < dist4){
                dist4 = abs(y-ey);
                x4 = ex , y4 = y;
                select4 = i;
            }
        }
    }

    if(select3 == select4){
        if(get(sx,sy,x3,y3) + t + get(x4,y4,ex,ey) <= ans){
            path.clear();
            ans = get(sx,sy,x3,y3) + t + get(x4,y4,ex,ey);
            path.push_back({0,x3,y3});
            path.push_back({select3,x4,y4});
            path.push_back({0,ex,ey});
        }
    }else{
        int xx = point[select3].first , yy = point[select4].second;
        if(get(sx,sy,x3,y3) + t + t + get(x4,y4,ex,ey) <= ans){
            path.clear();
            ans = get(sx,sy,x3,y3) + t + t + get(x4,y4,ex,ey);
            path.push_back({0,x3,y3});
            path.push_back({select3,xx,yy});
            path.push_back({select4,x4,y4});
            path.push_back({0,ex,ey});
        }
    }

    for(int i=1;i<=n;i++){
        auto [x,y] = point[i];
        int x3,y3,x4,y4;
        if(abs(x-sx) < abs(y-sy)){
            x3 = x , y3 = sx;
        }else{
            x3 = sx , y3 = y;
        }
        if(abs(x-ex) < abs(y-ey)){
            x4 = x , y4 = ex;
        }else{
            x4 = ex , y4 = y;
        }
        if(get(sx,sy,x3,y3) + t + get(x4,y4,ex,ey) <= ans){
            path.clear();
            ans = get(sx,sy,x3,y3) + t + get(x4,y4,ex,ey);
            path.push_back({0,x3,y3});
            path.push_back({i,x4,y4});
            path.push_back({0,ex,ey});
        }
    }

    printf("%.10lf\n",ans);
    cout << path.size() << "\n";
    for(auto [a,b,c] : path){
        cout << a << " " << b << " " << c << "\n";
    }

}

int main(){
    solve();
    return 0;
}
