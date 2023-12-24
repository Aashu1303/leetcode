class Solution {
public:
    int minOperations(string s) {
        if(s.length() == 1) return 0;
        int ans = 0, n = s.length();
        string temp1,temp2;
        char c = '1' , t = '0';
        for(int i = 0 ; i < n ; i++){
            temp1 += c;
            int x = (c - '0') ^ 1;
            c = (x + '0');
        }

        for(int i = 0 ; i < n ; i++){
            temp2 += t;
            int x = (t - '0') ^ 1;
            t = (x + '0');
        }

        int count1 = 0, count2 = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] != temp1[i]) count1++;
            if(s[i] != temp2[i]) count2++;
        }

        return min(count1,count2);
    }
};