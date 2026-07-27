class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxi=0;
       
        for(int i=0;i<n;i++){
            int currHt= heights[i];

            while(!st.empty() && currHt < heights[st.top()]){
                int ht=heights[st.top()];
                st.pop();

                int width=st.empty() ? i : i-st.top()-1;
                maxi=max(maxi,ht * width);
            }
            st.push(i);

        }
       while(!st.empty()){
            int ht = heights[st.top()];
            st.pop();
            
            int width = st.empty() ? n : n - st.top() - 1;
            maxi = max(maxi, ht * width);
        }

        return maxi;
    }
};