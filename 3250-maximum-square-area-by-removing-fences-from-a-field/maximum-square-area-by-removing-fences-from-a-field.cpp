class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        if(m == n){
            return (m-1)*(n-1);
        }
        int MOD = 1e9+7;
        int maxm = -1;
        hFences.insert(hFences.begin() ,{1,m});
        vFences.insert(vFences.begin() , {1,n});
        sort(vFences.begin() , vFences.end());
        sort(hFences.begin() , hFences.end());
        unordered_set<int> h;
        unordered_set<int> v;
        
        for(int i = 0 ; i < hFences.size() ; i++){
            for(int j = i+1 ; j < hFences.size() ; j++){
                h.insert(hFences[j] - hFences[i]);
            }
        }
        for(int i = 0 ; i < vFences.size() ; i++){
            for(int j = i+1 ; j < vFences.size() ; j++){
                v.insert(vFences[j] - vFences[i]);
            }
        }
        
        int s = 0;
        for(auto i : h){
            if(v.find(i) != v.end()){
                s = max(s , i);
            }
        }

        if(s != 0) maxm = (1LL*s*s)%MOD;
        return maxm;
    }
};