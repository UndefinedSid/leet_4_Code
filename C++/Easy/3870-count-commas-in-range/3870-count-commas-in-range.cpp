class Solution {
public:
    int countCommas(int n) {
        if (n < 1000)
            return 0;
        else if (n < 10000) {
            int cnt = n - 1000;
            return cnt + 1;
        } else {
            int cnt = n - 1000;
            return cnt + 1;
        }
        return 0;
    }
};