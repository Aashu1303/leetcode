class Solution {
public:
    int minimumLevels(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffix(n+1,0);

        for(int i = n-1 ; i >=0 ; i--){
            if(arr[i] == 0) suffix[i] = -1 + suffix[i+1];
            else suffix[i] = 1 + suffix[i+1];
        }
        int curr = 0;
        int ans = -1;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] == 1){
                curr++;
            }else{
                curr--;
            }

            if(curr > suffix[i+1] && i != n-1){
                ans = i+1;
                break;
            }
        }

        return ans;
    }
};