class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        i,j,ans=0,0,0
        freq=[0] * 3
        n=len(s)

        for j in range(n):
            freq[ord(s[j])- ord('a')] += 1
            while freq[0] > 0 and freq[1] > 0 and freq[2] > 0:
                ans += n - j
                freq[ord(s[i])- ord('a')] -= 1
                i += 1

        return ans