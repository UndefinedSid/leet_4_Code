class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        daysInMonth=[31,28,31,30,31,30,31,31,30,31,30,31]
        def isLeap(year):
            return year % 4 ==0 and (year % 100 !=0 or year % 400==0)

        def finder(strs):
            yr,mn,days =map(int,strs.split('-'))
            totalDays=0
            for y in range(1900,yr):
                totalDays += 366 if isLeap(y) else 365

            for m in range(mn-1):
                totalDays += daysInMonth[m]

            if mn > 2 and isLeap(yr):
                totalDays += 1

            totalDays += days

            return totalDays

            return sum(daysInMonth[:mn-1]) + days

        days1=finder(date1)
        days2=finder(date2)

        return abs(days1-days2)
