class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0 , n = s.length();
        for(auto &i : s){
            if(i == '1'){
                count++;
                i = '0';
            } 
        }
        int i = 0;
        s[n-1] = '1';
        count--;
        while(count > 0){
            s[i] = '1';
            count--;
            i++;
        }

        return s;
    }
};