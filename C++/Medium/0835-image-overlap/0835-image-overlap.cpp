class Solution {
public:
    int n;

    int finder(vector<vector<int>>& A, vector<vector<int>>& B,int offR,int offC){
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int bI=i + offR;
                int bJ=j + offC;

                if(bI < 0 || bI >= n || bJ < 0 || bJ >= n)
                    continue;

                if(A[i][j]==1 && B[bI][bJ]==1)
                    count++;
            }
        }
        return count;
    }

    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        n=A.size();

        int ans=0;

        for(int offR= -n+1;offR <n;offR++){
            for(int offC= -n+1;offC <n;offC++){
                int cnt=finder(A,B,offR,offC);
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};