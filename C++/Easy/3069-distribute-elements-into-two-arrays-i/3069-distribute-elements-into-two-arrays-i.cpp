class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans,arr;
        ans.push_back(nums[0]);
        arr.push_back(nums[1]);
    
        int x=0,y=0;

        for(int i=2;i<n;i++){
            if(ans[x] > arr[y]){
                ans.push_back(nums[i]);
                x++;
            }else{
                arr.push_back(nums[i]);
                y++;
            }
        }

        for(int val : arr){
            ans.push_back(val);
        }

        return ans;
    }
};