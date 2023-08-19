test = int(input())

tower1 = list(range(test + 1, 0, -1))
tower2 = [test + 1]
tower3 = [test + 1]

def dfs(stack, togo):
    print(tower1,tower2, tower3)
    if len(tower3) == test:
        return 1
    for i in togo:
        if i[-1] < stack[-1]:
            togo.pop(i)
    if not togo:
        return float('inf')
    min_value = float('inf')
    for j in togo:
        j.append(stack.pop())
        tmp = dfs(j, [ i for i in [tower1, tower2, tower3] if i != j] )
        if tmp < min_value:
            min_value = tmp
        stack.append(j.pop())
        
    return min_value + 1
            
            
print(dfs(tower1, [tower2,tower3]))
    
            
            
             