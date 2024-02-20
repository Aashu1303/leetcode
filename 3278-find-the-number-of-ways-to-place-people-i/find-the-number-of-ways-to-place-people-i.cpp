class Solution {
    bool check(int y1 , int y2 , int i , int j , vector<vector<int>> &v){
        for(int k = i+1 ; k < j ; k++){
            if(v[k][1] <= y1 && v[k][1] >= y2) return false;
        }
        return true;
    }
public:
    int numberOfPairs(vector<vector<int>>& v) {
        auto comp = [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        };
        sort(v.begin() , v.end() , comp);
        for(auto i : v){
            for(auto j : i) cout << j <<  " ";
            cout << endl;
        }
        int n = v.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(v[i][1] >= v[j][1]){
                    if(check(v[i][1], v[j][1], i, j, v)){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};