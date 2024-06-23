class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 1;
        multiset<int> s;
        int l = 0 , n = nums.size();
        for(int r = 0 ; r < n ; r++){
            s.insert(nums[r]);
            while((abs(*s.begin() - *s.rbegin()) > limit) && (l < r)){
                s.erase(s.find(nums[l]));
                l++;
            }
            int maxM = *s.begin();
            int minM = *s.rbegin();
            if(abs(maxM - minM) <= limit){
                ans = max(r-l+1 , ans);
                // cout << r << " " << l << endl;
            } 
        }
        return ans;
    }
};