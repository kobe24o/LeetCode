class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        a = tomatoSlices - 2*cheeseSlices
        if a < 0 or a%2==1:
            return []
        juwuba = a//2
        xiaohuangbao = cheeseSlices - juwuba
        if xiaohuangbao >= 0:
            return [juwuba, xiaohuangbao]
        return []