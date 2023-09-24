import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

class Field:
    def __init__(self, lst = []) -> None:
        self.field = lst
        self.next_cloud = set()
        self.cloud_disappear = set()
        self.total = 0
    
    def cycle(self, di, s, sett):
        # print('=====================================================')
        # print(sorted(sett - self.cloud_disappear))
        self.mandmcloud(di, s, sett)
        self.water_copy()


    def mandmcloud(self, di, s, sett):
        def move(cord, di, s):
            # N이 0이되고 -1은 N - 1 s이 되니 
            if di == 1:
                tmp = cord[1] - s
                while tmp < 0:
                    tmp += N
                while tmp >= N:
                    tmp -= N
                tmp2 = cord[0]

            elif di == 2:
                tmp = cord[1] - s
                while tmp < 0:
                    tmp += N
                while tmp >= N:
                    tmp -= N

                tmp2 = cord[0] - s
                while tmp2 < 0:
                    tmp2 += N
                while tmp2 >= N:
                    tmp2 -= N
                
            elif di == 3:
                tmp = cord[1]
                tmp2 = cord[0] - s
                while tmp2 < 0:
                    tmp2 += N
                while tmp2 >= N:
                    tmp2 -= N
                
            elif di == 4:
                tmp = cord[1] + s
                while tmp < 0:
                    tmp += N
                while tmp >= N:
                    tmp -= N

                tmp2 = cord[0] - s
                while tmp2 < 0:
                    tmp2 += N
                while tmp2 >= N:
                    tmp2 -= N

            elif di == 5:
                tmp2 = cord[0]
                tmp = cord[1] + s
                while tmp < 0:
                    tmp += N
                while tmp >= N:
                    tmp -= N
            elif di == 6:
                tmp = cord[1] + s
                while tmp < 0:
                    tmp += N
                while tmp >= N:
                    tmp -= N
                tmp2 = cord[0] + s
                while tmp2 < 0:
                    tmp2 += N
                while tmp2 >= N:
                    tmp2 -= N
            elif di == 7:
                tmp = cord[1] 
                tmp2 = cord[0] + s
                while tmp2 < 0:
                    tmp2 += N
                while tmp2 >= N:
                    tmp2 -= N
            else:
                tmp = cord[1] - s
                while tmp < 0:
                    tmp += N
                while tmp >= N:
                    tmp -= N
                tmp2 = cord[0] + s
                while tmp2 < 0:
                    tmp2 += N
                while tmp2 >= N:
                    tmp2 -= N
            return (tmp2, tmp)
        new_set = set()
        sub_set = set()
        # print('중간 이동만확인')
        # print(*A.field , sep='\n')
        # print()
        for i in sett:
            if i not in self.cloud_disappear:
                # self.field[i[0]][i[1]] -= 2
                # self.total -= 2
                if self.field[i[0]][i[1]] < 2:
                    sub_set.add(i)
                next = move(i, di, s)
                self.field[next[0]][next[1]] += 1
                self.total += 1
                new_set.add(next)
        # print('비가 내린후')
        # print(*A.field , sep='\n')
        # print()
        self.cloud_disappear = new_set
        self.next_cloud -= sub_set



    #I love Kim Sang Beom

    def water_copy(self):
        for i in self.cloud_disappear:
            for k in [[-1, 1], [1, 1], [1, -1], [-1, -1]]:
                if 0 <= i[0] + k[0] < N and 0 <= i[1] + k[1] < N:
                    self.field[i[0]][i[1]] += self.field[i[0] + k[0]][i[1] + k[1]] > 0
                    self.total += self.field[i[0] + k[0]][i[1] + k[1]] > 0
            
            if self.field[i[0]][i[1]] >= 2:
                self.next_cloud.add(i)


N, M = map(int, input().split())
A = Field()
for i in range(N):
    tmp = list(map(int, input().split()))
    for j in range(N):
        if tmp[j] > 1:
            A.next_cloud.add((i, j))
        A.total += tmp[j]
    A.field += [tmp]

# print(*A.field , sep='\n')
# print()
# print(A.next_cloud)
# print(A.total)

for _ in range(M):
    di, s = map(int, input().split())
    if _ == 0:
        A.cycle(di, s, {(N - 1, 0), (N - 1, 1), (N - 2, 0), (N - 2, 1)})
    else:
        for i in A.next_cloud:
            if i not in A.cloud_disappear:
                A.field[i[0]][i[1]] -= 2
                A.total -= 2
        A.cycle(di, s, A.next_cloud)

    # print(*A.field , sep='\n')
    # print()
for i in A.next_cloud:
    if i not in A.cloud_disappear:
        A.field[i[0]][i[1]] -= 2
        A.total -= 2
# print(*A.field , sep='\n')
print(A.total)
        
# 구름 이동 직전까지 계산