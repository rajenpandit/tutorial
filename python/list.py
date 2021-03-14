
list = [1,2,3,4]
print(list[1:3])
print(list[1:])
print(list[:3])

list2 = []
for x in list:
    list2.append(x*2)
print(list2)


list3 = [x*2 for x in list]

print("list3:",list3)