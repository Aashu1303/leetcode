class Solution {
public:
    int lengthOfLongestSubstring(string s){
        unordered_map<char, int> mp;
        int left = 0, right = 0;
        int n = s.length();
        if(n == 0) return 0;
        if(n == 1) return 1;
        int ans = INT_MIN;
        // abcdefgha
        while (right < n){
            while (mp[s[right]] != 0 && left < right){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
            mp[s[right]]++;
            right++;
        }
        return ans;
    }
};