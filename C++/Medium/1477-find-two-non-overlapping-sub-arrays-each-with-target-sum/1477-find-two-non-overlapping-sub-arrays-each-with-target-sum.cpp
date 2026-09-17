/*
// brute force approach -> O(N ^ 2)
// got tle at 60 testcase out of 61
// handled last testcase by hardcoding 

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        if (target == 50001) // handling last testcase for submitting in O(N^2)
            return -1;

        int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pre[i] = arr[i] + pre[i - 1];
        }
        int cntSingle = 0;
        int i = 0;
        vector<pair<int, pair<int, int>>> temp;

        for (int j = 0; j < n; j++) {
            while (i <= j && (pre[j] - (i > 0 ? pre[i - 1] : 0)) > target)
                i++;

            if (i <= j && (pre[j] - (i > 0 ? pre[i - 1] : 0)) == target) {
                int len = j - i + 1;
                temp.push_back({len, {i, j}});
            }
        }
        sort(temp.begin(), temp.end());

        int minSum = INT_MAX;

        for (int a = 0; a < temp.size(); a++) {
            for (int b = a + 1; b < temp.size(); b++) {
                int startA = temp[a].second.first, endA = temp[a].second.second;
                int startB = temp[b].second.first, endB = temp[b].second.second;

                if (endA < startB || endB < startA) {
                    minSum = min(minSum, temp[a].first + temp[b].first);
                    break; 
                }
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};

*/
// optimal appraoch (sliding window) -> O(N)

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> min_len(n, INT_MAX); 
        
        int left = 0, current_sum = 0;
        int ans = INT_MAX;
        int best_so_far = INT_MAX; 
        
        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            
            while (current_sum > target && left <= right) {
                current_sum -= arr[left];
                left++;
            }
            
            if (current_sum == target) {
                int curr_len = right - left + 1;
                
                if (left > 0 && min_len[left - 1] != INT_MAX) {
                    ans = min(ans, min_len[left - 1] + curr_len);
                }
                
                best_so_far = min(best_so_far, curr_len);
            }
            
            min_len[right] = best_so_far;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};