#include <bits/stdc++.h>
#define int long long
using namespace std;

int tar = (1 << 9) - 1;

int row[10],col[10];
int g[10][10];

signed main(){
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++){
            int x; cin>>x; x--;
            g[i][j] = x;
        }
    for(int i=1;i<=9;i+=3)
        for(int j=1;j<=9;j+=3){
            int sum = 0;
            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                    sum |= (1 << g[i+x][j+y]);
                }
            }
            if(sum != tar){
                cout << "No" << "\n";
                return 0;
            }
        }    
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            row[i] |= (1 << g[i][j]);
            col[j] |= (1 << g[i][j]);
        }
    }
    int f = 1;
    for(int i=1;i<=9;i++) f &= (row[i] == tar && col[i] == tar);
    cout << (f ? "Yes" : "No") << "\n";
    return 0;
}
