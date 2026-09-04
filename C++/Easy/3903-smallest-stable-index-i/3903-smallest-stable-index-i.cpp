class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> suffMin(n);
        suffMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffMin[i]=min(suffMin[i+1],nums[i]);
        }

        int preMaxi=nums[0];

        for(int i=0;i<n;i++){
            preMaxi=max(preMaxi,nums[i]);

            if(preMaxi - suffMin[i] <= k){
                int idx=i;
                return idx;
            }
        }
        return -1;
    }
};