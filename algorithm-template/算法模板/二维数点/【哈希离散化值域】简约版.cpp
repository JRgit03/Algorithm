vector<int> all;
// vec排序去重离散化
sort(all.begin(),all.end());
all.erase(unique(all.begin(),all.end()), all.end());

// 映射索引1...
int getPos(int x){
    int l = 0, r = all.size() - 1;
    return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
}