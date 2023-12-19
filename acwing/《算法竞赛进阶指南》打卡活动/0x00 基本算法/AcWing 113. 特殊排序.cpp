// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> res; res.push_back(1);
        for(int i=2;i<=N;i++){
            int l = 0, r = res.size() - 1; //cout << r << "\n";
            while(l < r){
                int mid = l + r >> 1;
                if(compare(res[mid],i)) l = mid + 1; // a[res[mid] < a[i]
                else r = mid;
            }
            if(compare(res[r],i)){ // 插入到r的后面 a[r] < a[i]
                vector<int> t;
                for(int j=0;j<res.size();j++){
                    t.push_back(res[j]);
                    if(j == r) t.push_back(i);
                } res = t;
            } else { // 插入到r的前面
                vector<int> t;
                for(int j=0;j<res.size();j++){
                    if(j == r) t.push_back(i);
                    t.push_back(res[j]);
                } res = t;
            }
        }
        return res;
    }
};