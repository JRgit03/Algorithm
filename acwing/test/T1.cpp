#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int numRows = 3;
    // string s = "PAYPALISHIRING";
    int numRows = 1;
    string s = "AB";
    vector<char> arr[numRows + 1];
    int cur = 1, f = 1;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        arr[cur].push_back(c);
        // cout << cur << "\n";
        cur += f;
        if (cur == numRows + 1)
            f = -1, cur = numRows - 1;
        if (cur == 0)
            f = 1, cur = 2;
    }
    string res = "";
    for (int i = 1; i <= numRows; i++){
        string tmp = "";
        for(auto c : arr[i]){
            tmp = tmp + c;
        }
        // cout << tmp << "\n";
        res = res + tmp;
    }
    cout << res << "\n";
    return 0;
}
