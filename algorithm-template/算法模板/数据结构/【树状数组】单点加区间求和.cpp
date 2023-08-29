/**
 * 普通树状数组维护的信息及运算
 * 要满足 结合律 且 可差分，如加法（和）、乘法（积）、异或等。
 * https://www.luogu.com.cn/problem/P3374
 */
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;
const int N = 5e5 + 10;
int n,m;
int a[N],tr[N];

int lowbit(int x){ //返回二进制最后一个1
	return x&-x;
}

void add(int x,int c){
    for(int i=x;i<=n;i+=lowbit(i)) tr[i] += c;
}

int sum(int x){ // sum(x)表示 a[1] + a[2] + ... + a[x]
	int res = 0;
	for(int i=x;i;i-=lowbit(i)) res += tr[i];
	return res;
}

int main(){
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i] , add(i,a[i]);
    for(int i=0;i<m;i++){
        int op,x,y; cin>>op>>x>>y;
        if(op == 1) add(x,y);
        else if(op == 2) cout << sum(y) - sum(x-1) << "\n";
    }
    return 0;
}
