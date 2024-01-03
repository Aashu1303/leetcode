class Solution {
    int countOne(string s){
        int count = 0;
        for(char c : s){
            if(c == '1') count++;
        }
        return count;
    }
public:
    int numberOfBeams(vector<string>& bank) {
        string temp  ="";
        int n = bank.size() , m = bank[0].size();
        //if(n == 1) return 0;

        for(int i = 0 ; i < m ; i++){
            temp += '0';
        }

        int prev = 0 , ans = 0;
        for(int i = 0  ; i <  n ; i++){
            if(bank[i] != temp){
                int c = countOne(bank[i]);
                ans += prev * c;
                prev = c;
            }
        }

        return ans;
    }
};