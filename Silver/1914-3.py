
test = int(input())

def moving(number, start, end):
    nowhere = [i for i in [1,2,3] if i != start if i != end][0]
    if number == 2:
        print(start, nowhere)
        print(start, end)
        print(nowhere, end)
        return 3
    else:
        a = moving(number - 1, start, nowhere)
        print(start, end)
        b = moving(number - 1, nowhere, end)
        return a + b + 1


# def movingwithout(number, start, end):
#     nowhere = [i for i in [1,2,3] if i != start if i != end][0]
#     if number == 2:
#         # print(start, nowhere)
#         # print(start, end)
#         # print(nowhere, end)
#         return 3
#     else:
#         a = movingwithout(number - 1, start, nowhere)
#         # print(start, end)
#         b = movingwithout(number - 1, nowhere, end)
#         return a + b + 1

if test > 20:
    print(2 ** test - 1)
else:
    print(2 ** test - 1)
    moving(test, 1, 3)

        
        
        