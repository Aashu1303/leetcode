class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n,0);
        vector<int> ans;
        int sum = accumulate(nums.begin(),nums.end() ,0);
        int actualSum = (n*(n+1))/2 , duplicate;
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]-1]++;
            if(freq[nums[i]-1] == 2){
                ans.push_back(nums[i]);
                duplicate = nums[i];
                break;
            }
        }
        ans.push_back(duplicate + (actualSum - sum));
        return ans;
    }
};