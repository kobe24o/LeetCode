class Solution:
    def transformArray(self, arr: List[int]) -> List[int]:
        temp = arr.copy()
        while True:
            for i in range(1, len(arr)-1):
                if arr[i-1] > arr[i] and arr[i] < arr[i+1]:
                    temp[i] += 1
                elif arr[i-1] < arr[i] and arr[i] > arr[i+1]:
                    temp[i] -= 1
            if temp == arr:
                break
            arr = temp.copy()
        return arr