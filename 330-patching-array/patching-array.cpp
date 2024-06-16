class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long count = 1;
        int i = 0;
        int ans = 0;

        while(count <= n){
            if(i < nums.size() && nums[i] <= count){
                count += nums[i];
                i++;
            }else{
                count *= 2LL;
                ans ++;
            }
        }
        return ans;
    }
};