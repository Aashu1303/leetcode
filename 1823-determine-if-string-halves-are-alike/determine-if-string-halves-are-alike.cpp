class Solution {
public:
    bool halvesAreAlike(string s) {
        int c1 = 0 , c2 = 0;
        int i = 0 , n = s.length();

        while(i < n/2){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                c1++;
            }else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                c1++;
            }
            i++;
        }    
        while(i < n){
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                c2++;
            }else if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                c2++;
            }
            i++;
        } 
        return c1 == c2;   
    }
};