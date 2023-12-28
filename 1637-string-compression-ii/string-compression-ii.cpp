int dp[101][27][101][101];
class Solution {
    int solve(string &s , int i , int prev , int freq, int k){
        if(k < 0) return INT_MAX;
        if(i >= s.length()){
            return 0;
        }
        if(dp[i][prev][freq][k] != -1) return dp[i][prev][freq][k];

        int delete_i = solve(s , i+1 , prev , freq, k-1);
        int keep_i = 0;

        if(s[i]-'a' == prev){
            int temp = 0;
            if(freq == 1 || freq == 99 || freq == 9){
                temp = 1;
            }
            keep_i = temp + solve(s,i+1,prev,freq+1,k);
        }else{
            keep_i = 1 + solve(s,i+1 , s[i]-'a' , 1 , k);
        }
        return dp[i][prev][freq][k] = min(keep_i , delete_i);
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(s,0,26,0,k);
    }
};