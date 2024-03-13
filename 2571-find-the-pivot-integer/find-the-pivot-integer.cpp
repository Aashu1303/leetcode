class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        int sum = n * (n+1) / 2;
        int prev = 0 , k = n/2;
        while(n != k){
            prev += n;
            //cout << sum << " " << prev << endl;
            if(sum == prev) return n;
            if(sum < prev) return -1;
            sum -= n;
            n--;
        }
        return -1;
    }
};