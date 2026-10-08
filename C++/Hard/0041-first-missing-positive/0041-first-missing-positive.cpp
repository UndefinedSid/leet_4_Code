class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        
        if( maxi < 0)
            return 1;

        set<int> st(nums.begin(), nums.end());
        int ans = INT_MIN;

        for (int i =1; i <= maxi; i++) {
            if (!st.count(i)) {
                return i;
                break;
            }
        }

        if (ans == INT_MIN) {
            return maxi + 1;
        }

        return 1;
    }
};