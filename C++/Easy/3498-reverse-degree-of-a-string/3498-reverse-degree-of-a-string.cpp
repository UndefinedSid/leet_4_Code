class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int prod=0;
        for(int i=0;i<n;i++){
            int ch=s[i]-'a';
            int idx=26-ch;
            cout << ch <<  " " << idx << endl;
            prod += (idx * (i+1));

        }
        return prod;
    }
};