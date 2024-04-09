class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0 , i = 0 , n = tickets.size();
        while(tickets[k] != 0){
            if(i == n) i = 0;
            if(tickets[i] == 0){
                i++;
                continue;
            }
            tickets[i]--;
            cout << tickets[i] << " ";
            ans ++;
            i++;
        }

        return ans;
    }
};