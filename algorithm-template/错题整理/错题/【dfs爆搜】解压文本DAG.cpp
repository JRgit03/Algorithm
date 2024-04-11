/**
题意：贝贝发明了一种新的压缩文本的方式，把常出现的字符部分用符号代替后单独写出。
     现在由你来帮忙解压一份文本，具体的解压方式请看输入格式、样例。
思路： 我们将第i段文本看成第i号节点，那么源文件就是第1号节点。如果有引用其他文本，则建立一条指向被引用文本的有向边。
      不难发现文件可以解压，当且仅当1号点出发能到达的节点集合，是一个有向无环图（DAG）。
      无法解压的情况，就是图里存在环。于是我们可以 dfs 解压到这个文本时，给其标记 vis[i] = true，解压完毕vis[i] = false。
**/
const int N = 11;
int n;
int vis[N];
string s[N];
string ans = "";

// search s[k]
void dfs(int k){
    for(int i=0;i<s[k].length();i++){
        if(s[k][i] != '*') ans += s[k][i];
        else if(s[k][i] == '*'){
            int nxt = s[k][++i] - '0';
            if(nxt > n) continue;
            if(!vis[nxt]){
                vis[nxt] = 1;
                dfs(nxt);
                vis[nxt] = 0;
            }else{ // exist loop
                cout << "#";
                exit(0); 
            }
        }
        if(ans.length() > 1000000){
            cout << "#";
            exit(0);
        }
    }
}

void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string str = "", t;
        while(1){
            getline(cin, t); 
            if(str != "") str += '\n';
            str += t;
            if(str.back() == '#') str.pop_back();
            if(t.back() == '#') break;
        }
        s[i] = str; //cerr << s[i] << "\n";
    }
    vis[1] = 1;
    dfs(1);
    vis[1] = 0;
    cout << ans;
    return;
}
