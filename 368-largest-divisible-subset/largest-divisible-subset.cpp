class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size() , lastIndex = 0, maxi = 1;
        vector<int>dp(n,1) , hash(n);
        sort(nums.begin() , nums.end());
        
        for(int i = 0 ; i < n ; i++){
            hash[i] = i;
            for(int j = 0 ; j < i ; j++){
                if((nums[i] % nums[j]) == 0){
                    if((dp[j]+1) > dp[i]){   // if we are taking the current element
                        dp[i] = dp[j] + 1;
                        hash[i] = j; // storing the next element location after a particular index
                    }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex] != lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        return temp;
    }
};