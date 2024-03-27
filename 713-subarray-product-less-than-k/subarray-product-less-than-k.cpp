class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0 , n = nums.size() , curr = 1;
        int l = 0 , r = 0;
        while(r < n){
            curr *= nums[r];
            while(l <= r && curr >= k){
                curr /= nums[l];
                l++;
            }
            ans += (r-l+1);
            r++;
        }
        return ans;
    }
};