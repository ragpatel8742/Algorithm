def removeOuterParentheses(self, S: str) -> str:
    result = []
        
    start = 0
    count = 0
    for idx, char in enumerate(S):
        count += 1 if char == '(' else -1
        if count == 0:
            result.append(S[start+1:idx])
            start = idx + 1
        
    return "".join(result)