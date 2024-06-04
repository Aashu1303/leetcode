class Solution {
public:
    int longestPalindrome(string s) {
        int even = 0 , odd = 0;
        map<char,int> mp;
        int count = 0;
        for(auto &i : s){
            mp[i]++;
        }

        for(auto &i : mp){
            if(i.second % 2 == 0){
                even += i.second;
            }else{
                odd += (i.second -1);
                count++;
            }
        }

        if(count) odd++;
        return even + odd;
    }
};