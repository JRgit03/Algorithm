#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 110;
int n;
int a[N][N];

int main(){
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n;j++) 
            cin>>a[i][j];
    for(int i=1;i<=n/2;i++) 
        for(int j=1;j<=n;j++)
            swap(a[i][j],a[n-i+1][j]);
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=n/2;j++)
            swap(a[i][j],a[i][n-j+1]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)   
            cout << a[i][j] << " \n"[j==n];
    return 0;
}
