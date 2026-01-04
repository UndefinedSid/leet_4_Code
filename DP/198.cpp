/*
PROBLEM -->> 198 (MEDIUM) -->> HOUSE ROBBER
TOPICS -->> ARRAY,DP,RECURSION + MEMOIZATION

You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping you from 
robbing each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

1 <= nums.length <= 100
0 <= nums[i] <= 400

Company Tags --> Amazon, OYO Rooms, Paytm, Walmart, Google, Flipkart, LinkedIn, Airbnb
Leetcode Link --> https://leetcode.com/problems/house-robber/
GfG Link --> https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1
Also Famous as -> Stickler Thief

*/

//Approach-1 (Recur + Memo) --> TIME COMP --> O(N)
class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int i, int& n) {
        if(i >= n)
            return 0;
        
        if(t[i] != -1)
            return t[i];
        
        int take = nums[i] + solve(nums, i+2, n); //steals ith house and moves to i+2 (because we can't steal adjacent)
        int skip = solve(nums, i+1, n); //skips this house, now we can move to adjacent next house
        
        return t[i]=max(take, skip);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        // Bottom Up approach 2
        int n=nums.size();
        vector<int> dp(n+1,-1);
        if(n==1)
        return nums[0];

        dp[0]=0;
        
        for(int i=1;i<=n;i++){
            int take=nums[i-1] + ((i-2 >=0) ? dp[i-2] : 0);
            int skip=dp[i-1];

            dp[i]=max(skip,take); 
        }
        int ans=dp[n];
        return ans;
        
        // with constant space ->> O(1) APPROACH

        int n=nums.size();
        if(n==1)
        return nums[0];

        int lastTwo=0;
        int prev=nums[0];        
        for(int i=2;i<=n;i++){
            int take=nums[i-1] + lastTwo;
            int skip=prev;

            int temp=max(skip,take); 
            lastTwo=prev;
            prev=temp;
        }
        return prev;
    }
};
