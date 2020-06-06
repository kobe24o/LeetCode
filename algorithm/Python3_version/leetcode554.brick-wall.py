class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        pos = 0
        n = len(wall)
        minbrick = float("inf")
        dict = {}
        for i in range(n):
            pos = 0
            for j in range(len(wall[i])-1):
                pos += wall[i][j]
                if pos not in dict:
                    dict[pos] = 1
                else:
                    dict[pos] += 1
        for p in dict:
            minbrick = min(minbrick, n-dict[p])
        if minbrick==float("inf"):
            return n
        return minbrick