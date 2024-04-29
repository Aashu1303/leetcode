class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0 , xorr = 0;
        for(auto i : nums){
            xorr ^= i;
        }
        xorr ^= k;
        while(xorr > 0){
            if((xorr&1)) ans++;
            xorr >>= 1;
        }
        return ans;
    }
};