class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> prefix(n+1 , 0);
        for(int i = 0 ; i < n ; i++){
            prefix[i+1] = prefix[i] + abs(s[i]-t[i]); 
        }
        int ans = 0;
        // for(auto i : prefix) cout << i << " ";
        cout << endl;
        for(int i = 1 ; i <= n ; i++){
            int x = lower_bound(prefix.begin() , prefix.begin() + i , prefix[i]-maxCost) - prefix.begin();
            ans = max(ans , i-x);
        }

        return ans;
    }
};