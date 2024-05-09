#define ll long long
class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
       long long ans = 0;
       sort(h.begin() , h.end() , greater<int>());
       int count = 0 , j = 0;
       for(int i = 0 ; i < k ; i++){
            while(j < h.size() && h[j] < count){
                j++;
            }
            if(j >= h.size()) break;
            ans += abs(h[j] - count);
            count++;
            j++;
       }
       return ans;
    }
};