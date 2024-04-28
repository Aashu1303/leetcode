class Solution {
    bool check(vector<int> &a , vector<int>&b , int x){
        int i = 0 , j = 0 , f = 0;
        while(i < a.size() && j < b.size()){
            if(a[i]+x != b[j]) f++;
            else j++;
            i++;
        }

        if(f > 2) return false;
        return true;
    }
public:
    int minimumAddedInteger(vector<int>& a, vector<int>& b) {
        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        int ans = INT_MAX;
        for(int i = 0 ; i < 3 ; i++){
            if(check(a,b,b[0]-a[i])){
                ans = min(ans , b[0] - a[i]);
            }
        }

        return ans;
    }
};