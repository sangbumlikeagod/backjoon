inp = 100


def fibonaci_devide(num1, num2):
    if num1 * inp // num2 == num2 * inp // (num1 + num2):
        return
    else:
        result = fibonaci_devide(num2, num1 + num2)
        if result != None:
            return result
        else:
            return max(num1 * inp // num2, num2 * inp // (num1 + num2) )


def fibonacci_substract(num1, num2):
    # print(num1, num2)
    if num1 - num2 < 0:
        return [num2, num1]
    else:
        lst1 = fibonacci_substract(num2, num1 - num2)
        lst1 += [num1]
        return lst1


return_ans = fibonacci_substract(inp, fibonaci_devide(1, 1))
print(len(return_ans))
print(' '.join(map(str, return_ans[::-1])))


for inp in range(1, 30001):
    return_ans1 = fibonacci_substract(inp, fibonaci_devide(1, 1))
    return_ans2 = fibonacci_substract(inp, fibonaci_devide(1, 1) - 1)

    if len(return_ans2) > len(return_ans1):
        return_ans = return_ans2
    else:
        return_ans = return_ans1
    print(len(return_ans))
    print(' '.join(map(str, return_ans[::-1])))



