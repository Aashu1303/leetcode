class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;  
        for(int i : nums){
            mp[i]++;
        }
        int ans = 0;
        for(auto i : mp){
            int s = i.second;
            if(s == 1) return -1;
            if(s%3 == 1){
                ans += ((s/3)-1) + 2;
            }else{
                ans += (s/3) + ((s%3)/2);
            }
        }
        return ans;
    }
};