# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountainArr: 'MountainArray') -> int:
        n=mountainArr.length()

        def finder(self,target:int,st:int,end:int,mountainArr:'MountainArray') -> int:
            while(st < end):
                mid=st + (end-st) // 2

                if mountainArr.get(mid) < mountainArr.get(mid+1):
                    st=mid+1
                else:
                    end=mid

            return st

        peakIdx=finder(self,target,0,n-1,mountainArr)

        def firstBinarySearch(self,target:int,st:int,end:int,mountainArr:'MountainArray')->int:
            while(st <= end):
                mid=st + (end - st) // 2

                if mountainArr.get(mid)==target:
                    return mid
                elif mountainArr.get(mid) < target:
                    st=mid+1
                else:
                    end=mid-1

            return -1


        ans = firstBinarySearch(self,target,0,peakIdx,mountainArr)

        def secondBinarySearch(self,target:int,st:int,end:int,mountainArr:'MountainArray')->int:
            while(st <= end):
                mid=st + (end-st)// 2
                if mountainArr.get(mid)==target:
                    return mid
                elif mountainArr.get(mid) < target:
                    end=mid-1
                else:
                    st=mid+1

            return -1


        if ans != -1:
            return ans
        else:
            secondAns= secondBinarySearch(self,target,peakIdx,n-1,mountainArr)

        if secondAns:
            return secondAns
        else:
            return -1
        