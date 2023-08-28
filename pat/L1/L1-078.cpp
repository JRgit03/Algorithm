#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main(){
    IOS;
    int n,m;cin>>n>>m;
    cin.ignore();//以清除缓冲区的缓存数据，防止getline读取时误读换行符‘\n’而导致非预期的运行结果。
    vector<string> vec;
    for(int i=0;i<n;i++){
        string s;getline(cin,s);//cout<<i<<" "<<s<<"\n";
        if(s.find("qiandao")==-1 && s.find("easy")==-1) vec.push_back(s);
    }
    //for(auto s : vec) cout << s << "\n";
    if(m>=vec.size()) cout << "Wo AK le" << "\n";
    else cout << vec[m] << "\n";
    return 0;
}
