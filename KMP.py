

print('hi you')

'''

어떤 단어를 배열화 함에 있어서 크기가 작을때랑 크기가 클때랑 다르다

내가 맨 앞에 애랑 같은지를 확인해야하고 내 앞에 있는 애가 같다는 표지를 갖고 있으면 0 에서 그 
표지만큼 떨어진 애랑 나랑 같은지를 확인해야 한다

핵심 개념은 
두 문자열의 중간을 비교하는 중에 다르지 않음이 밝혀졌다면

패턴문자열의 [ : i ] 까지와
원래 문자열의 [ k : k + i ] 까지가 같다는걸 의미한다. k는 0 이상의 임의의 수
근데 패턴 문자열의 i - 1 번째 문자와 0 번째 문자가 같다면 적어도 원래 문자열의 k 번째와 원래 문자열의
0번째 문자는 같다고 가정할 수 있는 것이다.

마찬가지로 패턴문자열이  i - p : i  p개의 문자가 0부터 p 개와 같으면 [ 0 : p - 1 ]
원래 문자열의 k : k + p - 1은 같다고 표현할 수 있는 것이다.

그러면 패턴 문자열의 0번째 부터를 원래 문자열의 [ k ] 번쨰 부터 놓고 다시 적용할 수 있을 것이다.


aaa.. => 
aac
aba

'''

'''

첫 번째 문자라면 -1을 리턴한다.

자기 자리에 0 + ( 자기가 앞의 몇번째 문자까지 같은지 알려주는 안내서 ) 를 추가한다
자기가 같은지를 알려주는 값을 리스트와 같이 리턴한다.


'''


def count_lst(string):

    if len(string) == 1:
        # print(len(string[: -1]), '란다')
        return [[-1, 0], 0]

    now_lst, indicator = count_lst(string[: -1])
    print(now_lst)
    print(string[-1] , string[now_lst[-1] + indicator])
    new_indicator = (string[-1] == string[now_lst[-1]])
    if new_indicator:
        now_lst += [now_lst[-1] + int(new_indicator)]
    else:
        now_lst += [0]
    return [now_lst, new_indicator]

def KMP(, pattern):

print(count_lst('abcdabcef'))


