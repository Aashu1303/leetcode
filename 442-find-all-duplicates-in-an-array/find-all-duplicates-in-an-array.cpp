class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n+1) , ans;
        for(int i = 0 ; i < nums.size() ; i++){
            if(v[nums[i]] == 1){
                ans.push_back(nums[i]);
            }
            v[nums[i]]++;
        }

        return ans;
    }
};