def Linear_Search(lst, key):
    for i in range(len(lst)):
        if (lst[i]==key):
            return i
    return -1

def Sentinel_Search(lst, key):
    size=len(lst)
    lst.append(key)
    i=0
    while(lst[i]!=key):
        i+=1
    if i==size:
        return -1
    else:
        return i

arr=[12, 15, 5, 7, 19, 17, 24, 34, 25]
key=4
print("Student found at position", Linear_Search(arr, key), "(Linear Search)")
print("Student found at position", Sentinel_Search(arr, key),"(Sentinel Search)")
