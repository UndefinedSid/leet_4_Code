from collections import defaultdict

class Solution:
    def longestPalindrome(self, words: list[str]) -> int:
        count = defaultdict(int)
        for word in words:
            count[word] += 1
            
        ans = 0
        central = False
        
        for word, freq in count.items():
            if word[0] == word[1]:
                if freq % 2 == 0:
                    ans += freq * 2
                else:
                    ans += (freq - 1) * 2
                    central = True 
            elif word < word[1]: 
                rev = word[1] + word[0]
                if rev in count:
                    ans += min(freq, count[rev]) * 4
                    
        if central:
            ans += 2
            
        return ans