import sys
from typing import Any
sys.stdin = open(__file__.split('\\')[-1][:-5] + '.txt','r')
sys.setrecursionlimit(100000)
test_case = int(input())
import heapq

class RoadtoGoal:
    def __init__(self, size) -> None:
        self.gogo = [0 , 0] + [float('inf')] * size - 1
        self.stack = []
        self.heap = []
        
    def findway(self, node):
        while self.heap:
            if node == N:
                return self.stack
            self.stack.append(node)
            
            if node in dic:
                for i in dic[node]:
                    if self.gogo[i[1]] > i[0] + self.gogo[node] and i[1] in self.stack:
                        if not self.heap:
                            return -1
                        else:
                            new_course = heapq.heappop(self.heap)
                            while new_course in  dic.get(self.stack[-1], []):
                                self.stack.pop()
                        self.gogo[i[1]] = i[0] + self.gogo[node]

                        heapq.heappush(self.heap, (self.gogo[i[1]], i[1]))
            else:
                if not self.heap:
                    return 
                else:
                    new_course = heapq.heappop(self.heap)
                    while new_course in  dic.get(self.stack[-1], []):
                        self.stack.pop()
        
        pass
for num in range(test_case):
    N, M = map(int,input().split())
    lst = [0, 0] + [float('inf')] * (N - 1)
    dic = {}
    for i in range(M):
        a, b, c  = map(int, input().split())
        dic[a] = dic.get(a, []) + [(-c, b)]