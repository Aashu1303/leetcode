class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0 , maxi = 0;
        for(auto i : nums){
            mp[i]++;
            maxi = max(mp[i] , maxi);
        } 
        for(auto i : mp){
            if(i.second == maxi){
                ans += i.second;
            }
        }

        return ans;
    }
};