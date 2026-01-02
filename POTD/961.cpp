/*
Problem 961 (EASY) --> N-repeated element in size 2N array

You are given an integer array nums with the following properties:
nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.
  */
  
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        
        int ans;
        int m=nums.size();
        unordered_map<int,int> mp;
        for(int val : nums){
            mp[val]++;
        }
        for(auto &p : mp){
            int val=p.first;
            int freq=p.second;
            if(freq==m/2){
                ans=val;
            }
        }
        return ans;
      
        // another approach
        int n=nums.size();
            while(true){
                int i=rand() % n;
                int j=rand() % n;
                if(i != j && nums[i]==nums[j])
                return nums[i];
            }
    }
};
