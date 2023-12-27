class Solution {
public:
    int minCost(string s, vector<int>& v) {
        int n = s.size();
        if(s.size() == 1) return 0;
        char prev = s[0]; 
        int prevMin = INT_MAX , ans = 0 , prevIndex =0;
        for(int i = 1 ; i < n ; i++){
            char curr = s[i];
            if(curr == prev){
                prevMin = min(v[prevIndex] , v[i]);
                ans += prevMin;
                if(v[prevIndex] < v[i]) prevIndex = i;
            }else{
                prevIndex = i;
            }
            prev = curr;
            //cout << prevIndex << " ";
        }
        //cout << endl;
        return ans;
    }
};