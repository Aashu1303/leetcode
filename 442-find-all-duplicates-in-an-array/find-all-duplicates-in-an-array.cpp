class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        vector<int> v(n+1) , ans;
        for(int i = 0 ; i < nums.size() ; i++){
            if(mp.find(nums[i]) != mp.end() && v[nums[i]] == 1){
                ans.push_back(nums[i]);
            }
            mp[nums[i]]++;
            v[nums[i]]++;
        }

        return ans;
    }
};