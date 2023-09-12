import sys

file = open('2304.txt', 'r')
sys.stdin = file

test_case = int(input())

lst = []
for num in range(test_case):
    M, N = map(int, input().split())
    lst.append((M, N))

# idx = test_case - 1
# while idx > 0:
#     for arg in range(idx):
#         if lst[idx][1] < lst[arg][1]:
#             lst[idx], lst[arg] = lst[arg], lst[idx]
#     idx -= 1

lst.sort(key=lambda x: x[1])
ans = 0


scope_min = lst[-1][0]
scope_max = lst[-1][0]

while lst:
    new_scope = lst.pop()
    if new_scope[0] in range(scope_min, scope_max):
        continue
    ans += new_scope[1]
    # 자기 자신을 더하는 거랑 다른애를 더하는거랑 안겹치게 못하나
    if new_scope[0] < scope_min:
        ans += (scope_min - 1 - new_scope[0]) * new_scope[1]
        scope_min = new_scope[0]
    if new_scope[0] > scope_max:
        ans += (new_scope[0] - scope_max - 1) * new_scope[1]
        scope_max = new_scope[0]

print(ans)





# 이전 보다 높은 애가 나오면  그애의 좌표와 이제까지중 제일 큰 놈의 좌표를 그대로 가지고 가서 차이로 넓이를 구한다
# 하지만 그 이후의 경우에는 완전히 반대가 되는데 가장 큰애를 기준으로 오른쪽은 어떤 애가 다음 애보다 작으면 갱신해줘야 한다.
# 또 딕셔너리로 만들어서 하자고 ? 싫어
# scope라는 범위를 만들어서










