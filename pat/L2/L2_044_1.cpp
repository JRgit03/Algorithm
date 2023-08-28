#include <bits/stdc++.h>
using namespace std;
const int N = 505 , INF = 0x3f3f3f3f;
int n;
int dist[N][N];
int sex[N]; //male - 1

vector<int> male,female;
int d1=INF,d2=INF;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(i==j)dist[i][i]=0;
            else dist[i][j]=INF;
        }
    for(int i=1;i<=n;i++){
        char c;cin>>c;sex[i] = (c=='M');
        int k;cin>>k;
        while(k--){
            int ob,d;scanf("%d:%d",&ob,&d);
            dist[i][ob] = min(dist[i][ob],d);
        }
    }
    bool f1 = false , f2 = false;
    for(int i=1;i<=n;i++){
        if(sex[i]) f1 = true;
        else f2 = true;
    }

    if(!f1 || !f2) return 0;

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    for(int i=1;i<=n;i++){
        int d = -1;
        for(int j=1;j<=n;j++){
            if(sex[i]^sex[j]){
                d = max(d,dist[j][i]);
            }
        }
        if(d!=-1){
            if(sex[i]){
                if(d < d1){
                    d1 = d;
                    male.clear();
                    male.push_back(i);
                 }else if(d==d1){
                     male.push_back(i);
                 }
            }else{
                if(d < d2){
                    d2 = d;
                    female.clear();
                    female.push_back(i);
                }else if(d==d2){
                    female.push_back(i);
                }
            } 
        }
    }
    if((int)female.size()){
        cout << female[0];
        for(int i=1;i<(int)female.size();i++) cout << " " << female[i];
        cout << "\n";
    }
    if((int)male.size()){
        cout << male[0];
        for(int i=1;i<(int)male.size();i++) cout << " " << male[i];
        cout << "\n";
    }
    return 0;
}
