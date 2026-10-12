class BusBooking:

    def __init__(self, n: int):
        self.n=n
        self.seatMap={}
        self.rowMap={}
        self.ans=0

    def toggle(self, seat: str) -> None:
        col=seat[0]
        row=int(seat[1:])

        if seat in self.seatMap:
            self.ans -= self.seatMap[seat]
            del self.seatMap[seat]
            self.rowMap[row].remove(col)
        else:
            cost=1
            if row not in self.rowMap:
                self.rowMap[row]=set()
                
            if col== 'A':
                if 'B' in self.rowMap[row]:
                    cost=3
            elif col=='D':
                if 'C' in self.rowMap[row]:
                    cost=3

            self.seatMap[seat]=cost
            self.ans +=  cost
            self.rowMap[row].add(col)
                

    def getTotalTime(self) -> int:
        return self.ans

    def getMinTime(self) -> int:
        return len(self.seatMap)


# Your BusBooking object will be instantiated and called as such:
# obj = BusBooking(n)
# obj.toggle(seat)
# param_2 = obj.getTotalTime()
# param_3 = obj.getMinTime()