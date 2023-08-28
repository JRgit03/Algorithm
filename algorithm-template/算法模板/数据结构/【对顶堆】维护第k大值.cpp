/**
 * 对顶堆维护第k大值
 * https://www.luogu.com.cn/problem/P1801 
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 2e5 + 10;
int n,m;
int a[N],u[N];

int main(){
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>u[i];
    priority_queue<int> big;
    priority_queue<int,vector<int>,greater<int> > small;
    int k = 0; 
    for(int i=1,j=1;i<=n;i++){
        // 插入
        if(big.size() && a[i] >= big.top()) small.push(a[i]);
        else big.push(a[i]);
        while(j<=m && u[j] == i) {
            j++,k++;
            // 调整
            while(big.size() < k) {
                int t = small.top(); small.pop();
                big.push(t);
            }
            while(big.size() > k){
                int t = big.top(); big.pop();
                small.push(t);
            }
            cout << big.top() << "\n";
        }
    }
    return 0;
}
