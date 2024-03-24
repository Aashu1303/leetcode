class Solution {
public:
    int minOperations(int k) {
        int ans = INT_MAX;
        for(int i = 1 ; i <= k ; i++){
            int curr = ceil((double)k / (double)i);//cout << curr << " " << i << endl;
            if(i-1+curr > ans) break;
            ans = min(i-1+(curr) , ans);
        }

        return ans-1;
    }
};