class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l =0 , r = 0;
        int ans = 0;
        vector<int> freq(26,0);
        while(r < s.size()){
            freq[s[r]-'a']++;
            while(freq[s[r]-'a'] > 2 && l < r){
                freq[s[l]-'a']--;
                l++;
            }
            ans = max(ans , r-l+1);
            r++;
        }

        return ans;
    }
};