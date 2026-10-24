class Solution:
    def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
        
        daysInMonth=[31,28,31,30,31,30,31,31,30,31,30,31]

        def finder(date_str :str)-> int:
            month,day=map(int,date_str.split('-'))
            return sum(daysInMonth[:month-1]) + day

        arr_a=finder(arriveAlice)
        arr_b=finder(arriveBob)

        lea_a=finder(leaveAlice)
        lea_b=finder(leaveBob)

        latestArrival=max(arr_a,arr_b)
        earlierDept=min(lea_a,lea_b)

        if latestArrival <= earlierDept:
            return earlierDept - latestArrival + 1

        return 0
