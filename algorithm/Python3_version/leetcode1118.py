class Solution:
    def numberOfDays(self, Y: int, M: int) -> int:
        d = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if M != 2:
            return d[M]
        if (Y%400 == 0) or (Y%4==0 and Y%100!=0):
            return d[2]+1
        return d[2]