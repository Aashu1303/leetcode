class Solution {
public:
    int timeRequiredToBuy(vector<int>& v, int k) {
        int ans = 0 , n = v.size() , x = v[k];
        for(int i = 0 ; i < n ; i++){
            if(i <= k){
                if(v[i] <= x ){
                    ans += v[i];
                }else{
                    ans += x;
                }
            }else{
                if(v[i] < x){
                    ans += v[i];
                }else{
                    ans += (x-1);
                }
            }
        }

        return ans;
    }   
};