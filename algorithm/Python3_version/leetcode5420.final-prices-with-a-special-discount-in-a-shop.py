class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        n = len(prices)
        for i in range(n-1):
            for j in range(i+1,n):
                if prices[j] <= prices[i]:
                    prices[i] -= prices[j]
                    break;
        return prices