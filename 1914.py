test = int(input())

tower1 = list(range(test + 1, 0, -1))
tower2 = [test + 1]
tower3 = [test + 1]

def dfs(stack, togo):
    print(tower1,tower2, tower3)
    if len(tower3) == test:
        return 1
    new_togo = []
    for i in togo:
        # print(i)
        if i[-1] > stack[-1]:
            new_togo.append(i)
            
    togo = new_togo
    print(togo)
    if not togo:
        min_value = float('inf')
        next = min([tower1, tower2, tower3], key=lambda x: x[-1])
        for j in [ i for i in [tower1, tower2, tower3] if i != next]:
            j.append(next.pop())
            next2 = max([tower1, tower2, tower3], key=lambda x: x[-1] % (test + 1))
            tmp = dfs(next2, [ i for i in [tower1, tower2, tower3] if i != next2] )
            if tmp < min_value:
                    min_value = tmp
            next.append(next2.pop())
        return min_value + 1
    else:
        min_value = float('inf')
        for j in togo:
            j.append(stack.pop())
            next = max([tower1, tower2, tower3], key=lambda x: x[-1] % (test + 1))
            tmp = dfs(next, [ i for i in [tower1, tower2, tower3] if i != next] )
            
            if tmp < min_value:
                min_value = tmp
            stack.append(j.pop())
            
        return min_value + 1
            
        
print(dfs(tower1, [tower2,tower3]))
    
            
            
             