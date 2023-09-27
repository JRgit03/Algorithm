/**
 * 
 * 单调递增栈：从 栈底 到 栈顶 递增，栈顶大
 * 单调递减栈：从 栈底 到 栈顶 递减，栈顶小
 * 
 * 单调栈应用场景
 * 
 * 要寻找任一元素右边（左边）第一个比自己大（小）的元素 O(n)
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
typedef pair<int,int> PII;
int n;
int a[N],ans[N];
int stk[N]; int tt;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>=1;i--){
        while(tt>0 && a[stk[tt]] <= a[i]) tt--;
        ans[i] = stk[tt];
        stk[++tt] = i;
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}