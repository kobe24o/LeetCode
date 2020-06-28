class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        freq = [0]*k
        for a in arr:
            freq[(a%k+k)%k] += 1
        if freq[0]&1:
            return False
        for i in range(1, k//2+1):
            if freq[i] != freq[k-i]:
                return False
        return True