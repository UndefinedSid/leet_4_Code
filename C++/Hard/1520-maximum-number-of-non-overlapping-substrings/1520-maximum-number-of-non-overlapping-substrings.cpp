class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int count[26] = {};
        int first[26], last[26];

        fill(first, first + 26, -1);
        fill(last, last + 26, -1);

        vector<int> order;

        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';

            if (count[c] == 0) {
                first[c] = i;
                order.push_back(c);
            }

            count[c]++;
            last[c] = i;
        }

        vector<string> ans;
        deque<array<int, 3>> qu;

        for (int c : order) {
            qu.push_front({first[c], last[c], count[c]});

            int left = INT_MAX;
            int right = INT_MIN;
            int total = 0;

            for (auto& item : qu) {
                total += item[2];
                left = min(left, item[0]);
                right = max(right, item[1]);

                if (total == right - left + 1) {
                    break;
                }
            }

            if (total == right - left + 1) {
                ans.push_back(s.substr(left, right - left + 1));
                qu.clear();
            }
        }

        return ans;
    }
};