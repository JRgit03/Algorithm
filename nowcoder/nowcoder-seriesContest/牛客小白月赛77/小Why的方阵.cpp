#include <bits/stdc++.h>
using namespace std;

int main(){
    int g[3][3];
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++)
            cin>>g[i][j];
    cout << (g[1][1] == g[2][2] || g[1][2] == g[2][1] ? "YES" : "NO") << "\n";
    return 0;
}
