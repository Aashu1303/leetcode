class Solution {
public:

    int fun(vector<vector<int>> &jobs, int ind, vector<int> &dp){
        if(ind >= jobs.size()) return 0;
        if(dp[ind] != -1) return dp[ind];
       
        int start = 0;
        int end = jobs.size()-1;
        int newjob = jobs.size()+1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(jobs[mid][0] >= jobs[ind][1]){
                newjob = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        int p = jobs[ind][2] + fun(jobs,newjob,dp);

        int np = fun(jobs,ind+1,dp);

        return dp[ind] = max(p,np);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n,vector<int>(3));
        vector<int> dp(n,-1);
        for(int i=0;i<n;++i){
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(),jobs.end());
        return fun(jobs,0,dp);
    }
};