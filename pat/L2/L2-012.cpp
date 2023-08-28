#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int n, m;
int a[N];

void build(int u){
    while (u / 2 > 0 && a[u / 2] > a[u]){
        swap(a[u / 2], a[u]);
        u /= 2;
    }
}

int main(){
    cin >> n >> m;
    for (int i=1; i <= n; i++){
        cin >> a[i];
        build(i);
    }
    map<int,int> mp;
    for(int i=1;i<=n;i++) mp[a[i]] = i;
    
    //for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];

    getchar();
    for(int i=0;i<m;i++){
        string str,s;getline(cin,str);
        stringstream stream(str);
        vector<string> vec;
        while(stream >> s) vec.push_back(s);
        int len = vec.size();
        if(len==4){
            int a = stoi(vec[0]);
            if(mp[a]==1)puts("T");
            else puts("F");
        }else if(len==5){
            int a = stoi(vec[0]) , b = stoi(vec[2]);
            if(mp[a]/2 == mp[b]/2)puts("T");
            else puts("F");
        }else if(len==6){
            int a = stoi(vec[0]) , b = stoi(vec[5]);
            if(vec[2]=="the"){
                if(mp[b]/2 == mp[a])puts("T");
                else puts("F");
            }else{
                if(mp[a]/2 == mp[b])puts("T");
                else puts("F");
            }
        }
    }
    return 0;
}
