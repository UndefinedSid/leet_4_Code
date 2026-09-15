class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int i=0,j = 0;
        int cnt = 0;

        while (i < n && j < n) {
            if (j - i + 1 >= k && isPalindrome(j-k+1, j, s)) {
                cnt++;
                i=j+1;
            }else if(j -i +1 >= k + 1 && isPalindrome(j-k,j,s)){
                cnt++;
                i=j+1;
            }
            j++;
        }
    
        return cnt;
    }
};