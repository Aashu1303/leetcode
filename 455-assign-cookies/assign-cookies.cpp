class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int n = g.size() , m = s.size();
        // left pointer will be on g and right pointer will be on s
        int left = 0 , right = 0;
        int ans = 0;
        while(left < n && right < m){
            if(g[left] <= s[right]){
                ans++;
                left++;
            }
            right++;
        }

        return ans;
    }
};