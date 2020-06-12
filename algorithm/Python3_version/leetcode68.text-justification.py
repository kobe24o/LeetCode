class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ans = []
        line = ""
        width = 0
        wc = 0
        def process(wc,line,width):
            if wc==1:
                line += ' '*(maxWidth-width)
                return line
            space = maxWidth-width
            n = space//(wc-1)
            pos = wc-1
            line = list(line)
            size = len(line)
            for i in range(size-1,-1,-1):
                if line[i]==' ':
                    line.insert(i, ' '*n)
                    space -= n
                    pos -= 1
                    if pos > 0 and space%pos==0:
                        n = space//pos
            line = "".join(line)
            return line
        i = 0
        while i < len(words):
            if len(line)==0:
                line = words[i]
                width = len(words[i])
                wc = 1
            else:
                if width+1+len(words[i]) <= maxWidth:
                    line += " "+words[i]
                    width += 1+len(words[i])
                    wc += 1
                else:
                    temp = process(wc,line,width)
                    ans.append(temp)
                    line = ""
                    width, wc = 0, 0
                    i -= 1
            i += 1
        line += ' '*(maxWidth-width)
        ans.append(line)
        return ans