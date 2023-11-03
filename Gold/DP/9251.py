import sys
sys.stdin = open(__file__.split('\\')[-1][:-3] + '.txt','r')
import sys
st = sys.stdin.readline


word1 = st().strip()
word2 = st().strip()

if len(word2) < len(word1):
    word1, word2 = word2, word1

dic = {}
def LCS(idx_w1, idx_w2):
    maxx = 0
    if idx_w1 < 0 or idx_w2 < 0:
        return 0
    
    if (idx_w1, idx_w2) in dic:
        return dic[(idx_w1, idx_w2)]
    k = 0
    while idx_w2 - k >= 0:
        if word1[idx_w1] == word2[idx_w2 - k]:
            maxx = max(maxx, LCS(idx_w1 - 1, idx_w2 - k - 1) + 1)
            break
        k += 1
    maxx = max(maxx, LCS(idx_w1 - 1, idx_w2))
    dic[(idx_w1, idx_w2)] = maxx
    return maxx
LCS(len(word1) - 1, len(word2) - 1)
print(dic[(len(word1) - 1, len(word2) -1)])