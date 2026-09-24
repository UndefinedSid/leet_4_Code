class Solution {
public:
    int n;
    int finder(int temp){
        int sum=0;
        while(temp > 0){
            int dgt=temp % 10;
            sum += dgt;
            temp /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        n=nums.size();
        for(int i=0;i<n;i++){
            if(finder(nums[i])==i){
                return i;
                break;
            }
        }
        return -1;
    }
};