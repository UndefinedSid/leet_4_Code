class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int ans=n;
        bool zeros=true;
        int xors=0;
        
        for(int val : nums){
            xors=(xors ^ val);
            if(val != 0){
                zeros=false;
            }
        }
        if(zeros)
            return 0;
        
        if(xors==0)
            return ans-1;
        else
            return ans;

    }
};