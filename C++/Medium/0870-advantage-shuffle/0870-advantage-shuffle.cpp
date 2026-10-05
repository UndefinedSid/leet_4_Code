class Solution {
public:
    /*
    // normal Approach with using binary search -> (O(N * log N))

    int finder(vector<int>& ans, int target,vector<bool>& taken) {
        int n = ans.size();
        int l=0,r=n-1;
        int bestIdx=-1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (ans[mid] > target) {
                bestIdx = mid;
                r = mid - 1;
        
            } else {
                l = mid + 1;
            }
        }

        if(bestIdx != -1){
            while(bestIdx < n && taken[bestIdx])
                bestIdx++;
        }

        if(bestIdx >= n)
            return -1;

        return bestIdx;
    }

    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        vector<int> ans(nums1);
        sort(ans.begin(), ans.end());
        vector<bool> taken(n, false);
        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            int idx = finder(ans, nums2[i], taken);
            if (idx != -1) {
                res[i] = ans[idx];
                taken[idx] = true;
            }else{
                int mini=0;
                while(taken[mini]){
                    mini++;
                }
                res[i]=ans[mini];
                taken[mini]=true;
            }
        }
        return res;
    }

    */

   //  Approach with MULTISET and UPPER_BOUND -> (O(N * log N))

    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        multiset<int> mulSet(nums1.begin(),nums1.end());
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            auto it=mulSet.upper_bound(nums2[i]);

            if(it != mulSet.end()){
                ans[i]= *it;
                mulSet.erase(it);
            }else{
                ans[i]= *mulSet.begin();
                mulSet.erase(mulSet.begin());
            }
        }
        return ans;
    }
};
