#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
       long long ans = 0;
       sort(h.begin() , h.end() , greater<int>());
       int count = 0 , j = 0;
       for(int i = 0 ; i < k ; i++){
            if(count > h[j]) break;
            ans += abs(h[j] - count);
            count++;
            j++;
       }
       return ans;
    }
};