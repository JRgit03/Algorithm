#include <bits/stdc++.h>
using namespace std;

map<string,int> months = {
    {"January", 1},{"February", 2},{"March", 3},{"April", 4},{"May", 5},{"June", 6},
    {"July", 7},{"August", 8},{"September", 9},{"October", 10},{"November", 11},{"December", 12}
};
string weekday[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

// 已知年月日求得对应星期
int whatday(int y, int m, int d) {
    // 1月视为13月,2月视为14月
    if(m == 1) y--,m = 13;
    else if(m == 2) y--,m = 14;
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}

int main(){
    int y,m,d; string M; while(cin>>d>>M>>y){
        m = months[M];
        cout << weekday[whatday(y,m,d)] << "\n";
    }
    return 0;
}

// https://www.acwing.com/problem/content/description/3492/
// in
// 9 October 2001
// 14 October 2001

// out
// Tuesday
// Sunday
