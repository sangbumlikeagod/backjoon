def solution(tickets):
    answer = []
    dic = {}
    for i in tickets:
        dic[i[0]] = dic.get(i[0], []) + [i[1]]
    for i in dic:
        i.sort()
    def search(arg):
        answer.append(dic[arg])
        if dic[arg]:
            search(dic[arg].pop(0))
        return    
            
            
        
        
        
    return answer

print(sorted(["ICN", "ATL", "ICN", "ICH", "ATK", "SFO"]), 'a'< 'c')

#자 ㅇ러디서 모자라졌을까 모든경우를 방문할 수 없는 경우는 존재하지 않는다고 했다. 그러니 모든 도시는 가능할 것
# 도시가 100개라면 이게 문제가 아니라 못가는 경우를 실현 안해놔서 그런듯 