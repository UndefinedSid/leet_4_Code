class Solution:
    def peakIndexInMountainArray(self, arr: list[int]) -> int:
        n=len(arr)
        left,right=0,n-1
        while left <= right:
            mid=left + (right-left) // 2
            if arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1]:
                return mid
            elif arr[mid] > arr[mid+1]:
                right=mid-1
            else:
                left=mid+1

        return 0
