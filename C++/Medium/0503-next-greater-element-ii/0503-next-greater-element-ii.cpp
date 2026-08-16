class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(2 * n);
        copy(nums.begin(), nums.end(), temp.begin());
        copy(nums.begin(), nums.end(), temp.begin() + n);
        vector<int> ans(n,-1);

        for (int i = 0; i < n; i++) {
            int j=i+1;
            while(j < i + n){
                if(nums[i] < temp[j]){
                    ans[i]=temp[j];
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};