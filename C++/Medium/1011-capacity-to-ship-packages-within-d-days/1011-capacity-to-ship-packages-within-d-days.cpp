class Solution {
public:
    int n;
    bool finder(vector<int>& weights, int mid, int days) {
        int currWt = 0;
        for (int wt : weights) {
            if (wt > mid)
                return false;

            if (currWt + wt > mid) {
                days--;
                currWt = wt;
            } else
                currWt += wt;

        }
        return days > 0;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        n = weights.size();

        int st = 0, end = 0;
        for(int w : weights){
            // st =max(st,w);
            end += w;
        }
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (finder(weights, mid, days)) {
                end=mid;
            } else
                st = mid +1;
        }
        return st;
    }
};