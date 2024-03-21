import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline
string = st().strip()
c_b = string.count('b')
end_p = len(string) + c_b
minn_b = 1000

while end_p - c_b >= 0:
    # print(end_p)
    # minn_a = min(c_a - string[end_p - c_b : end_p].count('a'), minn_a)
    local = 0
    local += string[ : end_p % len(string)].count('b') * (end_p // len(string))
    local += string[end_p - c_b : end_p].count('b')
    minn_b = min(c_b - local, minn_b)
    end_p -= 1
end_p = len(string)

print(minn_b)
