import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')


people = int(sys.stdin.readline())

can_we_see = []
ruqruq = []
return_value = 0


while people > 0:
    
    back_line = int(sys.stdin.readline())
    # print(can_we_see, ruqruq, return_value)
    while can_we_see and can_we_see[-1] < back_line:
        can_we_see.pop()
        return_value += ruqruq.pop()

    if can_we_see:
        if can_we_see[-1] == back_line:  
            return_value += ruqruq[-1]
            ruqruq[-1] += 1
            if len(ruqruq) == 1:
                return_value -= 1
             
        else: 
            can_we_see.append(back_line)
            ruqruq.append(1)
        return_value += 1
    else:
        can_we_see.append(back_line)
        ruqruq.append(1)

    
    people -= 1

print(return_value)
