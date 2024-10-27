#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using namespace std;

int f(string s){
    int h = stoi(s.substr(0,2)), m = stoi(s.substr(3));
    return (h - 1) * 60 + m;
}

signed main(){
    string l,r;
    int sum = 0;
    while(cin>>l>>r){
        cout << l << " " << r << "\n";
        sum += f(r) - f(l);
    }
    cout << sum << "\n";
    cout << 1.0 * sum / 60 * 20 + 140 << "\n";
    return 0;
}

/* 
7月 工时4907分钟  4907 / 60 * 20 + 140(出勤10天算两周 14/30*300) = 1775.67
08:50 11:07
12:49 18:14

08:55 18:25

08:53 09:01
12:19 20:23

08:46 08:55

09:00 18:13

08:58 18:28

09:00 18:26

08:55 18:38

08:55 18:04

09:01 18:14
 */

/*
8月 
09:03 18:08
18:28 19:58

09:09 18:24

08:59 19:03

08:55 18:49

09:01 18:48

08:58 18:42

08:56 18:42
*/
