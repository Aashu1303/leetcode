class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> v(5,0);
        v[1] = 0 , v[2] = 1 , v[3] = 1 , v[4] = 2;  
        for(int i : nums){
            mp[i]++;
        }
        int ans = 0;
        for(auto i : mp){
            while(i.second > 4){
                ans++;
                i.second -= 3;
            }
            if(i.second == 1) return -1;
            ans += v[i.second];
        }
        return ans;
    }
};