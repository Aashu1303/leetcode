class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int i = 0 , k = n-1;
        int j = 0;
        while(j < n){
            if(v[j] == 0 && i <= j){
                swap(v[i] , v[j]);
                i++;
            }else if(v[j] == 2 && j <= k){
                swap(v[j], v[k]);
                k--;
            }else{
                j++;
            }
        }
    }
};