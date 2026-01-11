
/*
PROBLEM --> 85 (HARD) -->> MAXIMAL RECTANGLE
TOPICS --> DP, STACK, MATRIX, MONOTONIC STACK
Given a rows x cols binary matrix filled with 0's and 1's, 
find the largest rectangle containing only 1's and return its area.

CONSTRAINT :-
1 <= rows, cols <= 200
matrix[i][j] is '0' or '1'

💡 Core Idea (High-Level)

We convert the 2D matrix problem into multiple 1D histogram problems.

Key Insight:

Treat each row as the base of a histogram
For every column, maintain the height of consecutive 1s
For each histogram, compute the largest rectangle area
This reduces the problem to repeatedly solving:

Largest Rectangle in Histogram (LeetCode 84)

🔍 Step-by-Step Approach
1️⃣ Convert Matrix Rows into Histograms

For the first row, build a histogram using values '0' and '1'
For every next row:
If cell is '1' → increase height
If cell is '0' → reset height to 0

Example:

Matrix:
1 0 1
1 1 1

Row 1 histogram: [1, 0, 1]
Row 2 histogram: [2, 1, 2]

2️⃣ Solve Largest Rectangle in Histogram

For each histogram:
Find Nearest Smaller to Left (NSL)
Find Nearest Smaller to Right (NSR)
Width = right[i] - left[i] - 1
Area = height[i] * width

🧩 Why NSL & NSR Work

For a bar i:
NSL(NEXT SMALLER TO LEFT) → first bar smaller on the left

NSR(NEXT SMALLER TO RIGHT) → first bar smaller on the right
This gives the maximum horizontal span where height[i] can form a rectangle.

🧪 Your Implementation (Validated)

You correctly:

Implemented NSL() and NSR() using stacks
Computed width and area correctly
Updated histogram row-by-row
Took the maximum area across all rows
✔️ Fully optimal solution

⏱️ Time & Space Complexity
Time Complexity
Each histogram: O(col)
For all rows: O(row × col)

✅ Optimal for this problem

Space Complexity
Histogram + stacks: O(col)

🔁 Similar LeetCode Problems
🔥 Very Similar (Must Solve)

LeetCode 84 – Largest Rectangle in Histogram
LeetCode 221 – Maximal Square
LeetCode 1504 – Count Submatrices With All Ones

🧠 Related Stack / Matrix Problems

LeetCode 739 – Daily Temperatures
LeetCode 907 – Sum of Subarray Minimums
LeetCode 2104 – Sum of Subarray Ranges

🌍 Similar Problems on Other Platforms
Codeforces

Rectangle Area in Binary Matrix
Histogram Area Variants

🔁GeeksForGeeks

Maximum size rectangle binary sub-matrix
Largest rectangular area in histogram

🔁InterviewBit

Max Rectangle in Binary Matrix

🏁 Final Takeaway

✔ Convert 2D → multiple 1D problems
✔ Stack-based histogram solution
✔ Optimal O(ROW × COL) complexity
✔ Classic interview + competitive programming problem

*/

class Solution {
public:

     vector<int> NSR(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        int pseudo_index = n;
        vector<int> right(n);
        for(int i = n-1; i>=0; i--) {
            if(st.empty()) {
                right[i] = pseudo_index;
            } else {
                while(!st.empty() && height[st.top()] >= height[i])
                    st.pop();
                if(st.empty())
                    right[i] = pseudo_index;
                else
                    right[i] = st.top();
            }
            st.push(i);
        }
        return right;
    }

    vector<int> NSL(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        int pseudo_index = -1;
        vector<int> left(n);
        for(int i = 0; i<n; i++) {
            if(st.empty()) {
                left[i] = pseudo_index;
            } else {
                while(!st.empty() && height[st.top()] >= height[i])
                    st.pop();
                if(st.empty())
                    left[i] = pseudo_index;
                else
                    left[i] = st.top();
            }
            st.push(i);
        }
        return left;
    }

    int maxAreaHist(vector<int>& height){
        int n=height.size();
        vector<int> rightIdx=NSR(height);
        vector<int> leftIdx=NSL(height);

        vector<int> width(n);

        for(int i=0;i<n;i++){
            width[i]=rightIdx[i] - leftIdx[i] - 1;
        }
        int max_area=0;
        for(int i=0;i<n;i++){
            int area=height[i] * width[i];
            if(area > max_area)
                max_area=area;
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        if(row==0)
        return 0;

        vector<int> height(col);

        for(int i=0;i<col;i++){
            if(matrix[0][i]=='1'){
                height[i]=1;
            }
            else{
                height[i]=0;
            }
        }

        int maxArea=maxAreaHist(height);

        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='0')
                height[j]=0;
                else{
                    height[j] += 1;

                }
            }
            maxArea=max(maxArea,maxAreaHist(height));
        }
        return maxArea;
    }

// 
};
