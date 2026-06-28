class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int temp = 0;

        for (int val : st) {
            if (st.find(val - 1)==st.end()) {
                int curr = val;
                int len = 1;

                while (st.find(curr + 1) != st.end()) {
                    curr += 1;
                    len++;
                }
                temp = max(temp,len);
            }
        }
        return temp;
    }
};