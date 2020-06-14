# -*- coding:utf-8 -*-
# @Python Version: 3.7
# @Time: 2020/6/14 17:54
# @Author: Michael Ming
# @Website: https://michael.blog.csdn.net/
# @File: leetcode0.test.py.py
# @Reference:
from typing import List


class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        d = {}
        for i in arr:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        count = list(d.values())
        count = sorted(count)
        i = 0
        for c in count:
            k -= c
            if k >= 0:
                i += 1
            if k <= 0:
                break
        return len(count) - i


s = Solution()
a = [5, 5, 4]
s.findLeastNumOfUniqueInts(a, 1)
