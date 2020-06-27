class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        import queue
        dir = [[1,0],[0,1],[0,-1],[-1,0]]
        m, n = len(grid), len(grid[0])
        step = 0
        vis = [[[False]*(k+1) for _ in range(n)] for _ in range(m)]
        q = queue.Queue(m*n*(k+1))
        q.put([0,0,0])
        vis[0][0][0] = True
        while not q.empty():
            size = q.qsize()
            while size > 0:
                qt = q.get()
                i = qt[0]
                j = qt[1]
                curs = qt[2]
                if i==m-1 and j==n-1:
                    return step
                for d in range(4):
                    ni = i+dir[d][0]
                    nj = j+dir[d][1]
                    if ni<0 or ni>=m or nj<0 or nj>=n:
                        continue
                    if grid[ni][nj] and curs+1 <= k and not vis[ni][nj][curs+1]:
                        vis[ni][nj][curs+1] = True
                        q.put([ni,nj,curs+1])
                    elif not grid[ni][nj] and not vis[ni][nj][curs]:
                        vis[ni][nj][curs] = True
                        q.put([ni,nj,curs])
                size -= 1
            step += 1
        return -1