
# class game:
#     def __init__(self, tasuk) -> None:
#         self.next = 0
#         self.score = 0
#         self.tasuk = tasuk
#     def inning(self, num):
        
#         out_count = 0
#         record = []
#         while out_count < 3:
#             if inning_result[num][self.tasuk[self.next]] == 0:
#                 out_count += 1
#             else:
#                 for i in range(len(record)):
#                     # print('\t', i)
#                     if record[i] < 4:
#                         record[i] += inning_result[num][self.tasuk[self.next]]
#                         # print(i)
                        
#                 record.append(inning_result[num][self.tasuk[self.next]])
#             self.next = (self.next + 1) % 9
#         for i in record:
#             if i >= 4:
#                 self.score += 1
#         # print(self.score, record)