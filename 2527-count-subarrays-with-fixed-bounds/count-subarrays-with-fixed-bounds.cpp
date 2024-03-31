class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int prevMin = -1 , prevMax = -1 , j = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > maxK || nums[i] < minK) j = i;

            if(nums[i] == minK) prevMin = i;
            if(nums[i] == maxK) prevMax = i;

            ans += max(min(prevMin,prevMax)- j,0)  ;
        }

        return ans;
    }
};