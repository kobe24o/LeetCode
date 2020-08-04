# """
# This is Sea's API interface.
# You should not implement it, or speculate about its implementation
# """
#class Sea(object):
#    def hasShips(self, topRight: 'Point', bottomLeft: 'Point') -> bool:
#
#class Point(object):
#   def __init__(self, x: int, y: int):
#       self.x = x
#       self.y = y

class Solution(object):
    def __init__(self):
        self.sum = 0
    def countShips(self, sea: 'Sea', topRight: 'Point', bottomLeft: 'Point') -> int:
        if not sea.hasShips(topRight, bottomLeft):
            return 0
        xmid = (topRight.x + bottomLeft.x)//2
        ymid = (topRight.y + bottomLeft.y)//2
        if topRight.x == bottomLeft.x and topRight.y == bottomLeft.y:
            self.sum += 1
            return self.sum
        elif bottomLeft.x == topRight.x:
            self.countShips(sea, Point(xmid, ymid), bottomLeft)
            self.countShips(sea, topRight, Point(xmid, ymid+1))
        elif bottomLeft.y == topRight.y:
            self.countShips(sea, Point(xmid, ymid), bottomLeft)
            self.countShips(sea, topRight, Point(xmid+1, ymid))
        else:
            self.countShips(sea, Point(xmid, ymid), bottomLeft)
            self.countShips(sea, Point(topRight.x, ymid), Point(xmid+1, bottomLeft.y))
            self.countShips(sea, Point(xmid, topRight.y), Point(bottomLeft.x, ymid+1))
            self.countShips(sea, topRight, Point(xmid+1, ymid+1))
        return self.sum