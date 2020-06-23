class Solution:
    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        p = [p1,p2,p3,p4]
        vec = []
        s = set(tuple(pi) for pi in p)
        if len(s) < 4:
            return False
        for i in range(3):
            for j in range(i+1, 4):
                dx = p[i][0]-p[j][0]
                dy = p[i][1]-p[j][1]
                vec.append([dx,dy])
        vec = sorted(vec, key=lambda a:a[0]*a[0]+a[1]*a[1])
        dis1 = vec[4][0]*vec[4][0]+vec[4][1]*vec[4][1];
        dis2 = vec[5][0]*vec[5][0]+vec[5][1]*vec[5][1];
        return (dis1==dis2) and (vec[4][0]*vec[5][0]+vec[4][1]*vec[5][1]==0)