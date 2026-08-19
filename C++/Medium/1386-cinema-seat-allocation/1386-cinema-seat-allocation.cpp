class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int sz = reservedSeats.size();
        sort(reservedSeats.begin(), reservedSeats.end());
        
        int ans = 0;
        int i = 0;
        int processedRows = 0;

        while (i < sz) {
            bool left = false;   
            bool right = false;  
            bool middle = false;  
            int row = reservedSeats[i][0];

            while (i < sz && reservedSeats[i][0] == row) {
                int s = reservedSeats[i][1];

                if (s == 2 || s == 3) {
                    left = true;
                } else if (s == 4 || s == 5) {
                    left = true;
                    middle = true;
                } else if (s == 6 || s == 7) {
                    right = true;
                    middle = true;
                } else if (s == 8 || s == 9) {
                    right = true;
                }
                i++;
            }

            if (!left && !right) {
                ans += 2;
            } else if (!left || !right || !middle) {
                ans += 1;
            }

            processedRows++;
        }

        ans += (n - processedRows) * 2;

        return ans;
    }
};