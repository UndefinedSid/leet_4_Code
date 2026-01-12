/*
PROBLEM -->> 1266 (EASY) --> "Minimum Time Visiting All Points,"
TOPICS --> 2D ARRAY, MATH, GEOMETRY, WEEKLY CONTEST
LEETCODE LINK --> https://leetcode.com/problems/minimum-time-visiting-all-points/description/?envType=daily-question&envId=2026-01-12
-------------------------------------------------------------------------------------------------------------------------
On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. 
Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:
In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).

You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order, but these do not count as visits.

points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000
-----------------------------------------------------------------------------------------------------------------
To solve LeetCode 1266, "Minimum Time Visiting All Points," 
you need to understand how movement works on a 2D grid when you can move horizontally, vertically, and diagonally.

The Step-by-Step Approach
1). Initialize a Variable: Create a variable total_time i.e. ans and set it to 0.
2). Iterate through Points: Loop through the array of points starting from the first point (i = 0) up to the second-to-last point (n-1).
3). Calculate Step Time: For every pair of consecutive points, Pi and P{i+1}:
    Find the absolute difference between their x-coordinates.
    Find the absolute difference between their y-coordinates.
    Take the maximum of these two values.
4). Accumulate: Add that maximum value to ans.
5). Return: After the loop finishes, return the total_time i.e. ans
  
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        for(int i=0;i<n-1;i++){
            int diffX=abs(points[i][0] - points[i+1][0]);
            int diffY=abs(points[i][1] - points[i+1][1]);
            ans=ans + max(diffX,diffY);
        }
        return ans;

    }
};
