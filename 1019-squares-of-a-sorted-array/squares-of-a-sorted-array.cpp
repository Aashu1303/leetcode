class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n-1;
        vector<int> ans;
        while(l <= r){
            if(abs(nums[l]) >= abs(nums[r])){
                ans.push_back(nums[l] * nums[l]);
                l++;
            }else{
                ans.push_back(nums[r] * nums[r]);
                r--;
            }
        }
        reverse(ans.begin() , ans.end());

        return ans;
    }
};