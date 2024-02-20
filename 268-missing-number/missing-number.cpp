class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n * (n  + 1)) / 2;
        int curr = 0;
        for(auto &i : nums) curr += i;

        if(sum - curr != 0){
            return (sum - curr);
        }
        return 0;
    }
};