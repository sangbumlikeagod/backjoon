

# 갈 수 있는 무한대의 방법에서 최적을 찾을 방법
# 차이가 엄청 크다고 가정할 때는 최대한 많이 곱하는게 답일 것 

# 동적으로 얘기해서 3가지중 가장 작은애 + 1이다. 그런데 이 문제는 뻗어나가는 문제라
# 한계를 정해주지 않으면 끝없이 나갈거다.

# 그럼 최대횟수를 정해주어야 한다. 
# 최대횟수란 목적지까지 갈수있는 확실한 수 -> 얘 차이에 따라 엄청나게 차이가 날것
# N이 더 큰 상황이라면 무조건 둘의 차가 답이라고 할 수 있다 
# 내가 5 동생이 3 2칸 그 차이만큼만,  *2가 항상 숫자를 크게하기때문에 반드시 참이다.

import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
sys.setrecursionlimit(100000)



N, K = map(int, sys.stdin.readline().split())

if K <= N:
    print(N - K)
else:
    limitcount = 0
    while 2 ** (limitcount + 1) * N < K:
        limitcount += 1
    # print(limitcount)
    
    limitcount += (K - 2 ** (limitcount) * N)
    # print(limitcount)
    
    # bfs로 풀 방법이 생각나긴함
    no_overlap = {}
    # def recur(num, count):
    #     print(num)
    #     if num > 100000 or num <= 0:
    #         return 100000
    #     if count >= limitcount:
    #         no_overlap[num] = 100000
    #         return 100000
            
    #     if num == K:
    #         return count
        
    #     if num in no_overlap:
    #         return no_overlap[num]
        
    #     # no_overlap[num] = count
    #     return min(recur(num + 1, count + 1), recur(num - 1, count + 1), recur(num * 2, count + 1))
        
        
    # def bfs(que, idx):
    #     next, count = que[idx]
        
    #     if next == K:
    #         return count
    #     que.append((next * 2, count + 1))
    #     que.append((next + 1, count + 1))
    #     que.append((next - 1, count + 1))
    #     return bfs(que, idx + 1)
    # # print(bfs([(5, 0)], 0))
    
    # def dfs(num, count):
    #     print(num)
        
    #     if num in no_overlap:
    #         if count < no_overlap[num]:
    #             no_overlap[num] = count
    #         else:
    #             return no_overlap[num]
    #     else:
    #         no_overlap[num] = count

    #     if num > K:
    #         return 100000
    #     elif num == K:
    #         return 0
    #     else:
    #         return min(dfs(num * 2, count + 1), dfs(num + 1, count + 1 ), dfs(num - 1, count + 1)) + 1

    # print(dfs(5, 0))
    
    def rev_dfs(K, count):
        # print(K)
        if K == N:
            return 0
        elif K > N:
            if K // 2 < N:
                if K % 2:
                    return min( K - N, N - (K + 1) // 2 + 2 , N - (K - 1) // 2 + 2) 
                else:
                    return min( K - N, N - K // 2 + 1)
            else:
                if K % 2:
                    return min(rev_dfs( (K + 1) // 2 , count + 2), rev_dfs( (K - 1) // 2 , count + 2)) + 2
                    
                else:
                    return rev_dfs( K // 2, count + 1) + 1


    print(rev_dfs(K, 0))
    
    from collections import deque
    que = deque()
    que.append((K, 0))
    low_count = 1000000000
    while que:
        next, count = que.popleft()
        if next == N:
            if count < low_count:
                low_count = count 
        elif next > N:
            if next // 2 < N:
                if next % 2:
                    if min( next - N, N - (next + 1) // 2 + 2 , N - (next - 1) // 2 + 2) + count < low_count:
                        low_count = min( next - N, N - (next + 1) // 2 + 2 , N - (next - 1) // 2 + 2) + count
                else:
                    if min( next - N, N - next // 2 + 1) + count < low_count:
                        low_count = min( next - N, N - next // 2 + 1) + count
            else:
                if next % 2:
                    que.append(((next + 1) // 2 , count + 2))
                    que.append(((next - 1) // 2 , count + 2))
                else:
                    que.append((next // 2, count + 1))
                    
    print(low_count)
                
    
    
    
    # 큰 애부터 시작해서 작은애로 올때 까지 짝수면 2로 나누고 홀수면 둘중 하나 하는 방식으로 하는거 어때
    # 경우의 수는 확 줄 거야 
    
    # que = [(5, 0)]
    # idx = 0
    # while idx <= len(que) - 1:
    #     print(que[idx])
    #     next, count = que[idx]
    #     if next == K:
    #         print(count)
    #     que.append((next * 2, count + 1))
    #     que.append((next + 1, count + 1))
    #     que.append((next - 1, count + 1))
    #     idx += 1
    
        
    # 처음부터 이걸로 해도 가능은 할 것 같어 아닐때까지 * 2를 하고 3방향으로 해야함 근데 
    # 

    
    # visited = {}
    

    # idx = 0
    # from collections import deque
    # que = deque()
    # que.append((5,0))
    # min_val = float('inf')
    
    # while que:
    #     N, count = que.popleft()
    #     # print(N, count)
    #     if N * 2 > K:
    #         if min_val > count + min( K - N , N * 2 - K + 1 , (N - 1) * 2 - K + 2):
    #             min_val =  count + min( K - N , N * 2 - K + 1 , (N - 1) * 2 - K + 2)
    #     else:
    #         if (N * 2) < K and count < min_val:
    #             que.append((N * 2, count + 1))
    #         if ((N + 1) * 2) < K and count < min_val:
    #             que.append(((N + 1) * 2, count + 2))
    #         if ((N - 1) * 2) < K and count < min_val:
    #             que.append(((N - 1) * 2, count + 2))
    #     idx += 1
        
    # print(min_val)
    