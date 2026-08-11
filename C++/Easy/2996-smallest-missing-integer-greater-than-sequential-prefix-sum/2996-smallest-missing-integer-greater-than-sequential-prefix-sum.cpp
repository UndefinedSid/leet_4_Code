class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();

        int pref=nums[0];

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1] + 1){
                pref += nums[i];
            }else{
               break;
            }
        }

        unordered_set<int> st(nums.begin(),nums.end());
        while(st.count(pref)){
             pref++;
        }
        return pref;
    }
};