class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp1,mp2;
        for(auto i : nums1){
            mp1[i]++;
        }
        vector<int> ans;
        for(auto i : nums2){
            if(mp1.count(i) && !mp2.count(i)){
                ans.push_back(i);
                mp2[i]++;
            }
        }

        return ans;
    }
};