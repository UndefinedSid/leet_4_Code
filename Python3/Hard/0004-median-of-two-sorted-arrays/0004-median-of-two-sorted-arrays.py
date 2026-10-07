class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        if(len(nums1) > len(nums2)):
            return self.findMedianSortedArrays(nums2,nums1)

        s1=len(nums1)
        s2=len(nums2)
        low,high=0,s1

        while low <= high:
            m1=low + (high-low) // 2
            m2= (s1 + s2 + 1) // 2 - m1

            l1=float("-inf") if m1==0 else nums1[m1-1]
            l2=float("-inf") if m2==0 else nums2[m2-1]

            r1= float("inf") if m1==s1 else nums1[m1]
            r2=float("inf") if m2==s2 else nums2[m2]

            if l1 <= r2 and l2 <= r1:
                if (s1 + s2) % 2 != 0:
                    return max(l1,l2)
                else:
                    return (max(l1,l2) + min(r1,r2)) / 2.0
            elif l1 > r2 :
                high=m1-1
            else:
                low=m1+1

        return 0.0
            