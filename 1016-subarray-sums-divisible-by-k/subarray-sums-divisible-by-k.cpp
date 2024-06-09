class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int sum = 0 , ans = 0;
        mp[0] = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            int target = sum % k;
            if(target < 0) target += k;
            if(mp.find(target) != mp.end()){
                ans+=mp[target]+1;
                mp[target]++;
            }else{
                mp[target] = 0;
            }
        }
        return ans;
    }
};