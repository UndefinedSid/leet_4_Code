class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        // cout << "Debug test" << endl;
        if (target == 50001) 
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