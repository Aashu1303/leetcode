class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = 0 , sum = 0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(auto i: nums){
            sum += i;
            if(mp[sum - goal] > 0){
                ans += mp[sum - goal];
            }

            mp[sum]++;
        }

        return ans;
    }
};