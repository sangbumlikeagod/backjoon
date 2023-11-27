
import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')

N, M = map(int, input().split())
mamamax = N * M
camera = []
room = []
for i in range(N):
    local = list(map(int, input().split()))
    for j in range(M):
        if local[j]:
            if local[j] != 6:
                camera.append((i, j))
            else: mamamax -= 1
    room += [local]

if not camera:
    print(mamamax)
else:
    
    securitiy_dic = {
        1 : [[0], [1], [2], [3]],
        2 : [[0, 1], [2, 3]],
        3 : [[0, 3], [1, 2], [0, 2], [1, 3]],
        4 : [[0, 1, 2], [1, 2, 3], [2, 0, 3], [0, 1, 3]],
        5 : [[0, 1, 2, 3]]
        }

    camera_dic = {}
    for i in camera:
        camera_lst = []
        # 하 상 우 좌 
        for lrud in [[-1, 0], [1, 0], [0, 1], [0, -1]]:
            k = 0
            tmp = set()
            # i
            while 0 <= i[0] + k * lrud[0] < N and 0 <= i[1] + k * lrud[1] < M and\
                room[i[0] + k * lrud[0]][i[1] + k * lrud[1]] != 6:
                    tmp.add((i[0] + k * lrud[0], i[1] + k * lrud[1]))
                    k += 1
            camera_lst += [tmp]
        for coverage in securitiy_dic[room[i[0]][i[1]]]:
            total_set = set()
            for specific in coverage:
                total_set = total_set | camera_lst[specific]
            camera_dic[i] = camera_dic.get(i, []) + [total_set]
        
    max_val = 0

    def search(idx, sett):
        global max_val 
        if idx == len(camera) - 1:
            for i in camera_dic[camera[idx]]:
                if len(sett | i) > max_val:
                    max_val = len(sett | i)
            return
                

        for i in camera_dic[camera[idx]]:
            search(idx + 1, sett | i)

    search(0, set())
    print(mamamax - max_val)
            
        
        
        

            


                
