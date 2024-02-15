class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size() , i =0 , j = 0;
        long long ans = -1;
        long long prev = 0;
        for(int j = 0 ; j < n ; j++){
            prev += nums[j];
            if(j-i+1 >= 3){
                if(nums[j] < (prev - nums[j])){
                    ans = max(ans , prev);
                }
            }
        }

        return ans;
    }
};