class Solution {
public:
    int maxScore(string s) {
        int ans = INT_MIN;
        int zeroes = 0 , ones = 0;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '1') ones++;
        }

        for(int i = 0 ; i < s.length() - 1 ; i++){
            if(s[i] == '1') ones--;
            else zeroes++;
            ans = max(ans , (zeroes + ones));
        }
        return ans;
    }
};