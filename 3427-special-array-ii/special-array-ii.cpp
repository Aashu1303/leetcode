class Solution {
    int bs(set<int>& s, int target) {
        auto it = s.lower_bound(target);

        if (it == s.begin() && *it > target) {
            return -1;
        }

        if (it != s.end() && *it == target) {
            return *it;
        }

        if (it == s.begin()) {
            return *it;
        }

        --it;
        return *it;
    }
public:
    vector<bool> isArraySpecial(vector<int>& arr, vector<vector<int>>& queries) {
        set<int> s;
        vector<bool> ans;

        for(int i = 1 ; i < arr.size() ; i++){
            if((arr[i] & 1) == (arr[i-1] & 1)){
                s.insert(i);
            }
        }

        for(int i = 0 ; i < queries.size() ; i++){
            int lower = queries[i][0], upper = queries[i][1];
            int x = bs(s,upper);
            if(x == -1){
                ans.push_back(true);
            }else{
                if(x > lower){
                    ans.push_back(false);
                }else{
                    ans.push_back(true);
                }
            }
        }
        return ans;
    }
};