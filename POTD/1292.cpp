https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/?envType=daily-question&envId=2026-01-19

PROBELM --> 1292 (MEDIUM) -->  Maximum Side Length of a Square with Sum Less than or Equal to Threshold
topics --> ARRAY, BINARY SEARCH, MATRIX, PREFIX SUM, CONTEST

Given a m x n matrix mat and an integer threshold, 
return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

** Key idea -->
* Build a 2D prefix sum
* Try square sizes from 1 → min(row, col)
* Use prefix sum to get square sum in O(1)
* Binary search or brute-force side length (both pass)

✅ Correct Working Code 

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size();
        int col = mat[0].size();

        // 2D prefix sum
        vector<vector<int>> pre(row + 1, vector<int>(col + 1, 0));

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }

        int ans = 0;

        for (int side = 1; side <= min(row, col); side++) {
            bool found = false;

            for (int i = side; i <= row; i++) {
                for (int j = side; j <= col; j++) {
                    int squareSum =
                        pre[i][j]
                      - pre[i - side][j]
                      - pre[i][j - side]
                      + pre[i - side][j - side];

                    if (squareSum <= threshold) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }

            if (found)
                ans = side;
            else
                break;
        }

        return ans;
    }
};

⏱ Time & Space Complexity
Metric	Value
Time	O(m × n × min(m,n)) (passes constraints)
Space	O(m × n)


🧠 Takeaway

For square sum problems → always use 2D prefix sum
Row/column prefix sums alone are error-prone

**  Binary search is the best optimization for this problem.

We’ll do this cleanly in 3 parts:

1️⃣ Why Binary Search Works

Define:

f(k) = true if there exists a k × k square with sum ≤ threshold

Key observation (monotonicity):

If f(k) is true, then f(k−1) is also true

If f(k) is false, then f(k+1) is also false

Why?

A larger square contains more elements → sum can only increase

✅ This monotonic behavior allows binary search on k.

2️⃣ How to Check a Given Side Length k

We use a 2D prefix sum to get any square sum in O(1).

Prefix sum formula

For bottom-right (i, j):

sum =
pre[i][j]
- pre[i - k][j]
- pre[i][j - k]
+ pre[i - k][j - k];

Check function
bool canForm(int k, vector<vector<int>>& pre, int threshold) {
    int row = pre.size() - 1;
    int col = pre[0].size() - 1;

    for (int i = k; i <= row; i++) {
        for (int j = k; j <= col; j++) {
            int sum = pre[i][j]
                    - pre[i - k][j]
                    - pre[i][j - k]
                    + pre[i - k][j - k];

            if (sum <= threshold)
                return true;
        }
    }
    return false;
}

3️⃣ Binary Search Implementation (Optimal)

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size();
        int col = mat[0].size();

        // 2D prefix sum
        vector<vector<int>> pre(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                pre[i][j] = mat[i - 1][j - 1]
                          + pre[i - 1][j]
                          + pre[i][j - 1]
                          - pre[i - 1][j - 1];
            }
        }

        int low = 0, high = min(row, col), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canForm(mid, pre, threshold)) {
                ans = mid;        // valid → try bigger
                low = mid + 1;
            } else {
                high = mid - 1;   // invalid → try smaller
            }
        }

        return ans;
    }

private:
    bool canForm(int k, vector<vector<int>>& pre, int threshold) {
        int row = pre.size() - 1;
        int col = pre[0].size() - 1;

        for (int i = k; i <= row; i++) {
            for (int j = k; j <= col; j++) {
                int sum = pre[i][j]
                        - pre[i - k][j]
                        - pre[i][j - k]
                        + pre[i - k][j - k];

                if (sum <= threshold)
                    return true;
            }
        }
        return false;
    }
};

⏱ Complexity
Approach	Time
Brute force	O(m · n · min(m,n))
Binary search	O(m · n · log(min(m,n))) 
🧠 Mental Model (Important)

Think of side length as the answer space:

false false false true true true
             ↑
         first valid k


Binary search finds the maximum valid k efficiently.

🔑 Takeaway

Binary search works because validity is monotonic

Prefix sum makes square checking O(1)

Combined → optimal & interview-grade solution

If you want:

🧪 step-by-step dry run

📈 visual grid explanation

🚀 further optimization ideas

Just tell me 👍

please explain the prefix sum diagram

Perfect question 👍
Let’s build the intuition visually for 2D prefix sum, step by step, like a diagram you can keep in your head during interviews.

1️⃣ What is a 2D Prefix Sum? (Big Picture)

A 2D prefix sum matrix pre stores:

pre[i][j] = sum of all elements in the rectangle
from top-left (0,0) to bottom-right (i-1, j-1)

So instead of repeatedly summing submatrices, we reuse past sums.

2️⃣ Original Matrix (Example)

Suppose mat is:

mat =
[ 1  2  3 ]
[ 4  5  6 ]
[ 7  8  9 ]

3️⃣ Prefix Sum Matrix Layout (with extra row & column)

We build pre of size (row+1) × (col+1)
First row and first column are zeros (very important).

pre =
[ 0  0  0  0 ]
[ 0  ?  ?  ? ]
[ 0  ?  ?  ? ]
[ 0  ?  ?  ? ]


This avoids boundary checks later.

4️⃣ Formula (Core Idea)

For every cell (i, j):

pre[i][j] =
    mat[i-1][j-1]
  + pre[i-1][j]      // sum above
  + pre[i][j-1]      // sum to the left
  - pre[i-1][j-1]    // remove double-counted area

5️⃣ Visual Meaning of the Formula

Think of it like this:

        ↑ pre[i-1][j]
   ┌───────────────┐
   │               │
←──┼   current     │
pre[i][j-1]        │
   │               │
   └───────┬───────┘
           ↑
     pre[i-1][j-1]  (overlap)


pre[i-1][j] → rectangle above

pre[i][j-1] → rectangle on the left

pre[i-1][j-1] → counted twice → subtract once

6️⃣ Filled Prefix Sum Matrix

After computing all cells:

pre =
[ 0   0   0   0 ]
[ 0   1   3   6 ]
[ 0   5  12  21 ]
[ 0  12  27  45 ]


Example:

pre[2][2] = 12 → sum of:

1 2
4 5

7️⃣ How to Get Any Square / Submatrix Sum in O(1)

To get sum of a square of side k
with bottom-right corner at (i, j):

sum =
pre[i][j]
- pre[i-k][j]
- pre[i][j-k]
+ pre[i-k][j-k]

8️⃣ Visual Diagram for Square Query
(i-k, j-k) ────────┐
    │              │
    │   WANTED     │
    │   SQUARE     │
    │              │
    └──────── (i,j)


ChatGPT can make mistakes. Check important info. See Cookie Preferences.
