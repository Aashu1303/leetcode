#define ll long long
class Solution {
    ll largestSquare(pair<pair<ll,ll>,pair<ll,ll>> &r1 , pair<pair<ll,ll>,pair<ll,ll>> &r2){
        ll x = max(r1.first.first , r2.first.first);
        ll y = max(r1.first.second , r2.first.second);
        ll x_end = min(r1.second.first , r2.second.first);
        ll y_end = min(r1.second.second , r2.second.second);
        
        if(x < x_end and y < y_end){
            ll side = min(x_end - x , y_end - y);
            return pow(side , 2); 
        }
        return 0;
    }
public:
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        int n = b.size();
        long long int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                pair<pair<ll,ll>,pair<ll,ll>> r1 , r2;
                //    x          y           x         y                x        y         x         y
                r1 = {{b[i][0],b[i][1]} , {t[i][0],t[i][1]}} , r2 = {{b[j][0] , b[j][1]},{t[j][0],t[j][1]}};
                ans = max(ans , largestSquare(r1,r2));       
            }
        }
        
        return ans;
    }
};