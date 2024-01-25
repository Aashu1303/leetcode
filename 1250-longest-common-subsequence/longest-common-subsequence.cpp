int dp[1001][1001];
int n, m;
string s1,s2;
class Solution {
    int solve(int i , int j){
        if(i >= n || j >= m){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i+1 ,j+1);
        }
        return dp[i][j] = max(solve(i+1,j) , solve(i,j+1));
    }
    
    public:
    int longestCommonSubsequence(string text1, string text2) {
        s1 = text1 , s2 = text2;
        n = text1.size() , m = text2.size();
        memset(dp , -1, sizeof(dp));
        return solve(0 , 0);
    }
};