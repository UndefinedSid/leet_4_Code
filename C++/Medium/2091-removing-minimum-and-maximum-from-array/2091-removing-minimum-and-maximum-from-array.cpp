class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxIdx=max_element(nums.begin(),nums.end()) - nums.begin();
        int minIdx=min_element(nums.begin(),nums.end()) - nums.begin();

        int i=min(minIdx,maxIdx);
        int j=max(minIdx,maxIdx);

        int ops1=j+1;
        int ops2=n-i;
        int ops3=i+1 + n-j;

        return min({ops1,ops2,ops3});
    }
};