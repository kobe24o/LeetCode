class Solution: # py3
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        mid = arr[(len(arr)-1)>>1]
        def cmp(x):
            return (abs(x-mid), x)
        arr = sorted(arr,key=cmp,reverse=True)
        return arr[0:k]