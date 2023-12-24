class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        if(m == n){
            return (m-1)*(n-1);
        }
        long long MOD = 1e9+7 , ans = -1;
        hFences.insert(hFences.begin() ,{1,m});
        vFences.insert(vFences.begin() , {1,n});
        sort(vFences.begin() , vFences.end());
        sort(hFences.begin() , hFences.end());
        unordered_map<int ,int> mp;
        
        for(int i = 0 ; i < hFences.size() ; i++){
            for(int j = i+1 ; j < hFences.size() ; j++){
                mp[hFences[j] - hFences[i]]++;
            }
        }
        for(int i = 0 ; i < vFences.size() ; i++){
            for(int j = i+1 ; j < vFences.size() ; j++){
                long long tem = vFences[j] - vFences[i];
                if(mp[tem]){
                    ans = max(ans , tem*tem);
                }
            }
        }
        return ans % MOD;
    }
};