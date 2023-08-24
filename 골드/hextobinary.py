ans = ''
for i in '1E06079861E79F99FE079861E79F8':
    ans += bin(int(i, base=16))[2:]
    
print(ans)
    
for i in range(0,len(ans),2):
    print(ans[i], end='')
1101011010011101101110101111011010101111011100
    