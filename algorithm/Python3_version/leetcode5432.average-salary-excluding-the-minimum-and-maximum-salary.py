class Solution:
    def average(self, salary: List[int]) -> float:
        salary.sort()
        s = sum(salary)-salary[0]-salary[-1]
        return s/(len(salary)-2)