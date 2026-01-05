/*
PROBLEM -->> 1975 (MEDIUM) --> MAXIMUM MATRIX SUM
TOPICS --> ARRAY, MATRIX, GREDDY,

You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. 
Return the maximum sum of the matrix's elements using the operation mentioned above.

n == matrix.length == matrix[i].length
2 <= n <= 250
-10^5 <= matrix[i][j] <= 10^5

*/

class Solution {
public:
    using ll = long long;

    ll maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum = 0;
        int negNum = 0;
        int mini = INT_MAX;  

        for (auto &row : matrix) {
            for (auto &val : row) {
                sum += abs(val);             
                mini = min(mini, abs(val)); 
                if (val < 0) {
                    negNum++;
                }
            }
        }

        if (negNum % 2 == 0) {
            return sum;
        } else {
            sum -= 2LL * mini;  
            return sum;
        }
    }
};

// TIME COMPLEXITY -->> O(N * M)
