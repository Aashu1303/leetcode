class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp , mp1;
        for(auto i : arr){
            mp[i]++;
        }

        for(auto i : mp){
            if(mp1[i.second] != 0) return false;
            mp1[i.second]++;
        }

        return true;
    }
};