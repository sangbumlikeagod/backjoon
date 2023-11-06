from collections import deque
s, e = map(int, input().split())
visited = [0] * (e + 1)
visited[s] = 1

round = 0
while e >= s:
    if e == s:
        print(round + 1)
        break

    if e % 10 == 1:
        e -= 1
        e //= 10
        round += 1
    elif e % 10 % 2 == 0:
        e //= 2
        round += 1
    else:
        print(-1)
        break
else:
    print(-1)
        
