class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd=n*n;
        int totalSum=2*n * (2*n+1) / 2;
        int sumEven=totalSum - sumOdd;

        int ans=__gcd(sumOdd,sumEven);
        return ans;
    }
};