class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0 , j = nums.size()-1;
        unordered_map<int,int> mp;
        int check = (nums.size())/2;
        while(i < j){
            mp[nums[i]]++;mp[nums[j]]++;
            if(mp[nums[i]] > check) return nums[i];
            if(mp[nums[j]] > check) return nums[j];
            i++; j--;
        }
        if(i == j){
            mp[nums[i]]++;
            if(mp[nums[i]] > check) return nums[i];
        }
        return 0;

    }
};