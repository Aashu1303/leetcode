class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n= nums.size();
        vector<int> v(n+1);
        for(auto i : nums){
            v[i]++;
            if(v[i] > 1) return i;
        }

        return -1;
    }
};