class Solution:

    def computeLPS(self, pattern: list[int], lps: list[int]):
        M = len(pattern)
        length = 0
        lps[0] = 0

        i = 1
        while i < M:
            if pattern[i] == pattern[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1
                    

    def search(self, pat: list[int], txt: list[int]) -> bool:
        N = len(txt)
        M = len(pat)

        lps = [0] * M
        self.computeLPS(pat, lps)

        i = 0  
        j = 0  

        while i < N:
            if pat[j] == txt[i]:
                i += 1
                j += 1

            if j == M:
                return True 
            elif i < N and pat[j] != txt[i]:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1
        return False


    def isRotation(self, vec1: list[int], vec2: list[int]) -> bool:
        txt = vec2 + vec2  
        return self.search(vec1, txt)

    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        sorted_nums = sorted(nums)

        result = 0

        for k in range(1, n + 1):
            if n % k != 0:
                continue

            valid = True
            for start in range(0, n, k):
                vec1 = nums[start : start + k]
                vec2 = sorted_nums[start : start + k]

                if not self.isRotation(vec1, vec2):
                    valid = False
                    break

            if valid:
                result += k

        return result