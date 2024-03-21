total_num = int(input())

left = 0
right = 0
road = []
# for i in range(total_num):
#     idx, height = map(int, input().split())
#     road.append((idx, height))


# def sort_b(arr):
#
#     def sort_even(arr):
#
#         if len(arr) == 2:
#             if arr[0] > arr[1]:
#                 arr[0], arr[1] = arr[1], arr[0]
#             return arr
#         else:
#             res = []
#             arr1 = sort_even(arr[:len(arr) // 2])
#             arr2 = sort_even(arr[len(arr) // 2:])
#             for idx in range(len(arr)):
#                 if arr1[idx] > arr2[idx]:
#                     res += [arr2[idx], arr1[idx]]
#                 else:
#                     res += [arr1[idx], arr2[idx]]
#             return res
#
#
#     if len(arr) % 2 == 1:
#         arr.append(float('inf'))
#         res = sort_even(arr)
#         res.pop()
#         return res
#     else:
#         return sort_even(arr)
#
#
# print(sort_b([5,5,498,77,64,5,9]))