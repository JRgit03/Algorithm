#include <bits/stdc++.h>
using namespace std;

struct Node{
	int id,x,y;
	bool operator < (const Node& o) const {
		return x != o.x ? x < o.x : y < o.y;
	}
};

int main(){
	int n; cin>>n;
	vector<Node> vec(n);
	for(int i=0;i<n;i++){
		int x,y; cin>>x>>y;
		vec[i] = {i+1, x, y};
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() / 2 << "\n";
	for(int i=0;i<n;i+=2)
		if(i + 1 < n){
			cout << vec[i].id << " " << vec[i+1].id << "\n";
		}
	return 0;
}