#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h,n;
int e[N],ne[N];

int main(){
    cin>>h>>n;
    for(int i=0;i<n;i++){
        int add;cin>>add;
        cin>>e[add]>>ne[add];
    }
    deque<int> q;
    while(h!=-1){
        q.push_back(h);
        h = ne[h];
    }
    vector<int> li;
    int cnt = 0;
    while(q.size()){
        if((cnt++)%2==0){
            li.push_back(q.back()); q.pop_back();
        }else{
            li.push_back(q.front()); q.pop_front();
        }
    }
    for(int i=0;i<cnt;i++){
        int x = li[i];
        if(i==0)printf("%05d %d",x,e[x]);
        else printf(" %05d\n%05d %d",x,x,e[x]);
    }
    printf(" -1");
    return 0;
}
