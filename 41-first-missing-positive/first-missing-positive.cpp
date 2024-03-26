class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1);

        for(int i = 0 ;i < nums.size() ; i++){
            if(nums[i] > 0 && nums[i] <= n){
                v[nums[i]]++;
            }
        }

        for(int i = 1 ; i <= n ; i++){
            if(v[i] == 0) return i;
        }

        return n+1;
    }
};