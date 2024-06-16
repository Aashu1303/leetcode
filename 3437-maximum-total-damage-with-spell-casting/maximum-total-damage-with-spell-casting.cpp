class Solution {
    map<long long ,long long> m;
    long long solve(int i,vector<long long>& v,vector<long long>& dp)
    {
        if(i>=v.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        long long not_take=0,take=0;
        if(i+1<v.size() && v[i+1]>v[i]+2)
        {
            take=(1ll*v[i]*m[v[i]])+solve(i+1,v,dp);
                
        }
        else if(i+2<v.size() && v[i+2]>v[i]+2)
        {
            take=(1ll*v[i]*m[v[i]])+solve(i+2,v,dp);   
        }
        else
        {
            take=(1ll*v[i]*m[v[i]])+solve(i+3,v,dp);  
        }
        not_take=solve(i+1,v,dp);
        
        return dp[i]=max(take,not_take);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
       
        vector<long long> dp(power.size()+1,-1);
        vector<long long> v;
        for(int i=0;i<power.size();i++)
        {
            if(m[power[i]]==0)
            {
                v.push_back(power[i]);
            }
            m[power[i]]++;
        }
        sort(v.begin(),v.end());
        return solve(0,v,dp);
    }
};