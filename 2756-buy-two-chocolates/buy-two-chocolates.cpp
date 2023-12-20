class Solution {
public:
    int buyChoco(vector<int>& nums, int money) {
        int Min = min(nums[0],nums[1]);
        int secondMin = max(nums[0] , nums[1]);
        int  n = nums.size();

        for(int i = 2 ; i < n ; i++){
            if(nums[i] < Min){
                secondMin = Min;
                Min =  nums[i];
            }else if(nums[i] < secondMin){
                secondMin = nums[i];
            }
        }
        int sum = Min+secondMin;
        if(sum <= money) return money-sum;
        return money;
    }
};