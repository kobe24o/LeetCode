class Solution:
    def maskPII(self, S: str) -> str:
        at = '@' in S
        ans = ""
        if at:
            if S[0].isupper():
                ans = S[0].lower()+"*****"
            else:
                ans = S[0]+"*****"
            idx = S.index('@')
            for i in range(idx-1, len(S)):
                if S[i].isupper():
                    ans += S[i].lower()
                else:
                    ans += S[i]
        else:
            count = 0
            last4 = ""
            for i in range(len(S)-1,-1,-1):
                if S[i].isdigit():
                    count += 1
                    if len(last4)<4:
                        last4 = S[i]+last4
            if count==10:
                ans = "***-***-"+last4
            else:
                ans = "+"+'*'*(count-10)+"-***-***-"+last4
        return ans