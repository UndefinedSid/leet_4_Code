class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int cntEven=0,cntOdd=0;
        int mini=INT_MAX;

        for(int val : nums1){
            if(val % 2 == 0){
                cntEven++;
            }else
                cntOdd++;

            mini=min(mini,val);
        }
        if(cntEven==0 || cntOdd==0 || mini % 2 != 0)
            return true;
        else
        return false;
    }
};