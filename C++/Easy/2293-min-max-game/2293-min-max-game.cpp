class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];

        while(n > 1){
            vector<int> newNums(n/2,0);
            for(int i=0;i<n/2;i++){
                if(i % 2==0)
                    newNums[i]=min(nums[i*2],nums[i*2 + 1]);
                else
                    newNums[i]=max(nums[i*2],nums[i*2 + 1]);
            }
          
            nums=newNums;
            n /= 2;
        }
        return nums[0];
    }
};