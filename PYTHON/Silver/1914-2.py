
test = int(input())

tower1 = list(range(test + 1, 0, -1))
tower2 = [test + 1]
tower3 = [test + 1]

def recur(tower1, tower2, tower3):
    print(tower1, tower2, tower3)
    if len(tower3) == test + 1:
        return 1
    next = max([tower1, tower2, tower3], key=lambda x: x[-1] % (test + 1))
    togo = [ i for i in [tower1, tower2, tower3] if i != next if next[-1] < i[-1]]
    min_value = float('inf')
    print(togo)
    if not togo:
        next = min([tower1, tower2, tower3], key=lambda x: x[-1])
        togo = [ i for i in [tower1, tower2, tower3] if i != next if next[-1] < i[-1] % (test + 1)]
        for i in togo:
            i.append(next.pop())
            tmp = recur(tower1, tower2, tower3)
            next.append(i.pop())
            if tmp < min_value:
                min_value = tmp
    else:       
        for i in togo:
            if i[-1] > next[-1]:
                i.append(next.pop())
                tmp = recur(tower1, tower2, tower3)
                next.append(i.pop())
                if tmp < min_value:
                    min_value = tmp
    return min_value + 1  

print(recur(tower1, tower2, tower3))    
    
    