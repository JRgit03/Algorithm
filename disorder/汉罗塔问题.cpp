#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int step = 0;

// move(n,a,b,c) 将n个盘从a移动到c借助b
void move(int n,char A,char B,char C){
    if(n == 1){
        step++;
        cout << "move " << A << " to " << C << "\n";
    }else{
        move(n-1,A,C,B);
        step++; //将第n个盘移动到C
        cout << "move " << A << " to " << C << "\n";
        move(n-1,B,A,C);
    }
}

void solve(){
    int n; cin>>n;
    move(n,'A','B','C');
    cout << "step: " <<  step << "\n";
}

int main(){
    IOS; solve();
    return 0;
}
