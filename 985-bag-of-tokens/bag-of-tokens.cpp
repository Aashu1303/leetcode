class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0 , ans = INT_MIN;
        sort(tokens.begin(),tokens.end());
        int i = 0 , j = tokens.size()-1;
        while(i <= j){
            if(tokens[i] <= power){
                power -= tokens[i];
                score++;
                i++;
            }else{
                if(score > 0){
                    power += tokens[j];
                    score--;
                    j--;
                }else{
                    break;
                }
            }
            ans = max(ans , score);
        }
        
        return ans == INT_MIN ? 0 : ans;
    }
};