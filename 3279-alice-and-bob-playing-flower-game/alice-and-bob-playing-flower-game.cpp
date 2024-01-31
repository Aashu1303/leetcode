class Solution {
     
public:
    long long flowerGame(int n, int m) {
        long long evenC = 0 ,  oddC = 0 , evenAC = 0 , oddAC = 0;
        for(int i = 1 ; i <= n ; i++){
            if(i%2) oddC++;
            else evenC++;
        }
        for(int i = 1 ; i <= m ; i++){
            if(i%2) oddAC++;
            else evenAC++;
        }

        long long ans = (evenAC * oddC) + (evenC * oddAC);
        return ans;
    }
};