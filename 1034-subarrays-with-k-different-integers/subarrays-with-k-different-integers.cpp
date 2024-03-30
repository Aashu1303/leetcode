class Solution {
    int solve(int k , vector<int>& nums){
        int n = nums.size();
        vector<int> v(n+1,0);
        int count = 0 , ans = 0;
        int i = 0 , j = 0;
        while(j < n){
            v[nums[j]]++;
            if(v[nums[j]] == 1) count++;
            while(count > k && i < j){
                v[nums[i]]--;
                if(v[nums[i]] == 0) count--;
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        if(k == 1) return solve(1,nums);
        int ans = solve(k,nums) - solve(k-1,nums);
        return ans;
    }
};