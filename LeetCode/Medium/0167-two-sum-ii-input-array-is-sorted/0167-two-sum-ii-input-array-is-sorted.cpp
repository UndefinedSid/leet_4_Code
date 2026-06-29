class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int> ans;
        int st=0,end=n-1;

        while(st < end){
            int currSum=numbers[st] + numbers[end];
            if(currSum==target)
                return {st+1,end+1};
            else if(currSum < target)
                st++;
            else
                end--; 
        }
        return {};
    }
};