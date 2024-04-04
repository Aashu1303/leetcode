class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int temp = x;
        while(x > 0){
            sum += (x % 10);
            x = x / 10;
        }
        if(temp % sum) return -1;
        return sum;
    }
};