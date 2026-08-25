class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());

        unordered_set<int> st(nums.begin(),nums.end());

        int mul=k;
        while(st.count(mul)){
            mul += k;
        }
        return mul;

    }
};