#include <bits/stdc++.h>
using namespace std;

int toNum(char c){
    if(c>='0' && c<='9')   
        return c - '0';
    return c - 'a' + 10;
}

char toChar(int x){
    if(x>=0 && x<=9) return (char)(x+'0');
    return (char)('a'+x-10);
}

int main(){
    string s1,s2;cin>>s1>>s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int l1 = s1.length() , l2 = s2.length() , t = 0;
    vector<char> res;
    for(int i=0;i<max(l1,l2);i++){
        char c1 = ( i < l1 ? s1[i] : '0') , c2 = ( i < l2 ? s2[i] : '0');
        int n1 = toNum(c1) , n2 = toNum(c2);
        int sum = n1 + n2 + t; t = sum/30;
        res.push_back(toChar(sum%30));
        //cout << n1 << " " << n2 << " " << sum << " " << toChar(sum) << "\n";
    }
    if(t) res.push_back(toChar(t));
    reverse(res.begin(),res.end());
    int st = 0;
    while(st+1<(int)res.size() && res[st]=='0')st++;
    for(int i=st;i<(int)res.size();i++) cout << res[i];
    return 0;
}
