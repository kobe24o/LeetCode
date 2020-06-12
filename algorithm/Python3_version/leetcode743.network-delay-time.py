class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        cost = [[float('inf')]*(N+1) for _ in range(N+1)]
        for t in times:
            cost[t[0]][t[1]] = t[2]
        for k in range(1,N+1):
            for i in range(1,N+1):
                for j in range(1,N+1):
                    if cost[i][k] != float('inf') and cost[k][j] != float('inf')\
                                        and cost[i][j] > cost[i][k]+cost[k][j]:
                        cost[i][j] = cost[i][k]+cost[k][j]
        maxt = 0
        for i in range(1,N+1):
            if i==K:
                continue
            if cost[K][i] == float('inf'):
                return -1
            maxt = max(maxt, cost[K][i])
        return maxt