class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int odd = 0 , l = 0 , ans = 0;
        queue<int> dq;
        for(int r = 0 ; r < n ; r++){
            if(nums[r] & 1){
                dq.push(r);
                odd++;
            }
            while(odd > k){
                odd -= (nums[l] % 2);
                if(dq.front() == l) dq.pop();
                l++; 
            }
            if(odd == k){
                int f = r - dq.front();
                ans += (r - l + 1) - f;
                // cout << first << " " << second << endl;
            } 
        }
        return ans;
    }
};