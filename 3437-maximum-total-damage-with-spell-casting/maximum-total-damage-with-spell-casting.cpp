class Solution {
long long dp[100001];
    map<long long,long long> m;
    long long solve(int i,vector<long long>& v)
    {
        if(i>=v.size())
        {
            return 0;
        }
        if(dp[i] != -1)
        {
            return dp[i];
        }
        long long not_take=0,take=0;
        if(i+1<v.size() && v[i+1]>v[i]+2)
        {
            take=(1ll*v[i]*m[v[i]])+solve(i+1,v);
                
        }
        else if(i+2<v.size() && v[i+2]>v[i]+2)
        {
            take=(1ll*v[i]*m[v[i]])+solve(i+2,v);   
        }
        else
        {
            take=(1ll*v[i]*m[v[i]])+solve(i+3,v);  
        }
        not_take=solve(i+1,v);
        
        return dp[i]=max(take,not_take);
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
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
        memset(dp,-1,sizeof(dp));
        return solve(0,v);
    }
};