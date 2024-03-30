class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n= nums.size();
        int i = 0 , j = 0 , l = 0 ;// (i_bada);
        int ans = 0;
        // vector<int> v(n+1);
        // using hashmap 
        unordered_map<int,int> mp;
        while(j < n){
            mp[nums[j]]++;

            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
                l = i;
            }

            while(mp[nums[i]] > 1){
                mp[nums[i]]--;
                i++;
            }

            if(mp.size() == k){
                ans += (1 + i - l);
            }
            j++;
        }

        return ans;
    }
};