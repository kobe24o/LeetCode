class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        m = {}
        ans = [""]*len(names)
        for i in range(len(names)):
            if names[i] not in m:
                m[names[i]] = 1
                ans[i] = names[i]
            else:
                num = m[names[i]]
                while names[i]+'('+str(num)+')' in m:
                    num += 1
                ans[i] = names[i]+'('+str(num)+')'
                m[names[i]] = num+1
                m[ans[i]] = 1
        return ans