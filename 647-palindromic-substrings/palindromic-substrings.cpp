class Solution {
    bool isPalindrome(int i , int j , string &s){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<int> dp(n,1);
        for(int i = 1 ; i < n ; i++){
            dp[i] += dp[i-1];
            for(int j = 0 ; j < i ; j++){
                if(isPalindrome(j,i,s)){
                    dp[i]++;
                }
            }
        }
        for(auto i : dp) cout << i << " ";
        return dp[n-1];
    }
};