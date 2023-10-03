import sys
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
N, M = map(int,input().split())

 

dic = {0 : [(0, 1)]}
for i in range(M):
    a, b, c  = map(int, input().split())
    dic[a] = dic.get(a, []) + [(-c, b)] # dic 은 값 : 가는데 필요한 비용, 위치이다 
import heapq
# print(dic)
overlap = [0] * (N + 1)
heap = []

class Road:
    def __init__(self,root_tuple) -> None:
        self.roadaround =  [0, 0] + [float('inf')] * (N)
        self.heap = [root_tuple]
        self.stack = []
        self.ans = -1
    def findroad(self): 
        while self.heap:
            # print(self.roadaround)
            value, node, prev = heapq.heappop(self.heap)
            self.stack.append(node)

            if node == N:
                if node in dic:
                    for i in dic[node]:
                        if i[0] < 0:
                            self.ans = -1 
                            return
                if value == self.roadaround[N]:
                    self.ans = self.stack[:]
                if self.heap:
                    while self.stack and self.stack[-1] != self.heap[0][2]:
                        self.stack.pop()
                    continue
                else:
                    break
            if node in dic:
                for i in dic[node]:
                    # print(self.roadaround[i[1]] , self.roadaround[node])
                    if self.roadaround[i[1]] > i[0] + self.roadaround[node]:
                        if i[1] in self.stack:
                            if not self.heap:
                                self.ans = -1
                                break
                            else:
                                while self.stack and self.stack[-1] != self.heap[0][2]:
                                    self.stack.pop()
                                if i[1] in self.stack:
                                    return
                                continue
                        # print('yes')
                        self.roadaround[i[1]] = i[0] + self.roadaround[node] 
                        heapq.heappush(self.heap, (self.roadaround[i[1]], i[1], node))
                        # print(self.heap)
                            # 지금 나의 위치만 알려주는 것 ( )
                if not self.heap:
                    break
                else:
                    # print(self.stack[-1], self.heap[0][2])
                    while self.stack and self.stack[-1] != self.heap[0][2]:
                        self.stack.pop()
                    continue
            else:
                if not self.heap:
                    self.ans = -1
                    break
                else:
                    while self.stack and self.stack[-1] != self.heap[0][2]:
                        self.stack.pop()
                    continue
                

                
a = Road((0, 1, 0))
a.findroad()
if a.ans != -1:
    print(' '.join(map(str, a.ans)))
else:
    print(-1)



            

