class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
       int n=nums.size(); 
       int ans=1;

       if(n==1 || n==2)
        return n;

        while(n >= ans)
            ans = ans * 2;

        return ans;
    }
};