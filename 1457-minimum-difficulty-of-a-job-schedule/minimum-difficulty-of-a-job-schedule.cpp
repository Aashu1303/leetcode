int dp[301][301][11];
class Solution {
    private:
        int solve(int index, int jobsLeft , int daysLeft , vector<int> &v){
            if(daysLeft == 1){
                int maxm = INT_MIN;
                for(int i = index ; i < v.size() ; i++){
                    maxm = max(v[i] , maxm);
                }
                return maxm;
            }
            if(dp[index][jobsLeft][daysLeft] != -1) return dp[index][jobsLeft][daysLeft]; 
            int ans = INT_MAX;
            int currDifficulty = INT_MIN;
            int to = (jobsLeft - daysLeft + index + 1);
            for (int i = index; i < to; i++)
            {
                currDifficulty = max(v[i], currDifficulty);
                jobsLeft--;
                int futureDifficulty = dp[index][jobsLeft][daysLeft];
                if(futureDifficulty == -1){
                    dp[index][jobsLeft][daysLeft] = solve(i+1, jobsLeft, daysLeft - 1, v); 
                    futureDifficulty = dp[index][jobsLeft][daysLeft];
                }
                ans = min(ans, (futureDifficulty + currDifficulty));
            }
            return ans;
        }
public:
    int minDifficulty(vector<int>& v, int d) {
        int n = v.size();
        if(n < d){
            return -1;
        }
        int sum = accumulate(v.begin() , v.end() , 0); // if all jobs are 0
        if(sum == 0) return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,n,d,v);
    }
};