class BrowserHistory:
    def __init__(self, homepage: str):
        self.pos = 0
        self.stk = [homepage]

    def visit(self, url: str) -> None:
        self.pos += 1
        self.stk = self.stk[0:self.pos]
        self.stk.append(url) 

    def back(self, steps: int) -> str:
        self.pos = max(0, self.pos-steps)
        return self.stk[self.pos]

    def forward(self, steps: int) -> str:
        self.pos = min(len(self.stk)-1, self.pos+steps)
        return self.stk[self.pos]