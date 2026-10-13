class Solution:
    def evenOddBit(self, n: int) -> list[int]:
        even,odd,i=0,0,0

        while n > 0:
            if n & 1:
                if i % 2==0:
                    even += 1
                else:
                    odd += 1
            
            n >>= 1
            i += 1

        return [even,odd]
