class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ans = 0 , curr = 0;
        mp[curr] ++;

        for(int i = 0 ; i < n ; i++){
            curr += nums[i];
            if(mp.count(curr-k)){
                ans+=mp[curr-k];
            }
            mp[curr]++;
        }

        return ans;
    }
};