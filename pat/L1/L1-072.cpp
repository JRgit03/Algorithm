#include <bits/stdc++.h>
using namespace std;

int reward[] = {10000,36,720,360,80,252,108,72,54,180,72,180,119,36,306,1080,144,1800,3600};
int flag,g[10];
bool has[10];

int main(){
    for(int i=0;i<9;i++) {
        cin>>g[i];
        if(!g[i]) flag=i;
        has[g[i]] = true;
    }
    int x=0; while(has[x])x++; g[flag] = x;
    for(int i=0;i<3;i++){
        int x,y;cin>>x>>y;
        x = (x-1) * 3 + y - 1; //cout << "x= " << x << "\n";
        cout << g[x] << "\n";
    }
    int op;cin>>op;
    if(op>=1 && op<=3){
        if(op==1) cout << reward[g[0]+g[1]+g[2]-6] << "\n";
        else if(op==2) cout << reward[g[3]+g[4]+g[5]-6] << "\n";
        else cout << reward[g[6]+g[7]+g[8]-6] << "\n";
    }else if(op>=4 && op<=6){
        if(op==4) cout << reward[g[0]+g[3]+g[6]-6] << "\n";
        else if(op==5) cout << reward[g[1]+g[4]+g[7]-6] << "\n";
        else cout << reward[g[2]+g[5]+g[8]-6] << "\n";
    }else{
        if(op==7) cout << reward[g[0]+g[4]+g[8]-6] << "\n";
        else if(op==8) cout << reward[g[2]+g[4]+g[6]-6] << "\n";
    }
    return 0;
}
