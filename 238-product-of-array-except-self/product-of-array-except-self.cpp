class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n+1,1);
        for(int i = n-1 ; i >= 0 ; i--){
            suffix[i] = (i == n-1 ? nums[i] : suffix[i+1] * nums[i]);
        }
        int prev = 1;
        for(int i = 0 ; i < n ; i++){
            suffix[i] = prev * suffix[i+1];
            prev *= nums[i];
        }
        suffix.pop_back();
        return suffix;
    }
};