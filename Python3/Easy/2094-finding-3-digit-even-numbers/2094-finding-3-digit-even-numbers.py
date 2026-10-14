class Solution:
    def findEvenNumbers(self, digits: list[int]) -> list[int]:
        freq=[0] * 10
        n=len(digits)
        ans=[]
        for i,val in enumerate(digits):
            freq[val] += 1

        for i in range(1,10):
            if freq[i]==0:
                continue
            else:
                freq[i] -= 1
            
            for j in range(10):
                if freq[j]==0:
                    continue
                else:
                    freq[j] -= 1

                for k in range(0,10,2):
                    if freq[k]==0:
                        continue
                    else:
                        freq[k] -= 1
                    
                    num = i * 100 + j * 10 + k
                    ans.append(num)

                    freq[k] += 1
                
                freq[j] += 1
            
            freq[i] += 1

        
        return ans


