class Solution {
public:
    using ll = long long;
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        
        if ( sum > (ll)num * 9) 
            return "";
            
        for (int pos = 0; pos < num; pos++) {
            for (int i = 9; i >= 0; i--) {
                int rem = num - 1 - pos;
        
                if (sum - i >= 0 && sum - i <= (ll)rem * 9) {
                    ans += to_string(i);
                    sum -= i;
                    break;
                }
            }
        }
        return ans;
    }
};