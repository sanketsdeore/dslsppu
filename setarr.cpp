def removeDuplicate(d):
    lst=[]
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst

def intersection(lst1,lst2):
    lst3=[]
    for val in lst1:
        if val in lst2:
            lst3.append(val)
    return lst3

def union(lst1,lst2):
    lst3=lst1.copy()
    for val in lst2:
        if val not in lst3:
            lst3.append(val)
    return lst3

def diff(lst1,lst2):
    lst3=[]
    for val in lst1:
        if val not in lst2:
            lst3.append(val)
    return lst3

def sym_diff(lst1,lst2):
    lst3=[]
    D1=diff(lst1,lst2)
    D2=diff(lst2,lst1)
    lst3=union(D1,D2)
    return lst3

def nCnB(lst1,lst2,lst3):
    lst4=diff(lst1,union(lst2,lst3))
    return lst4

def CBnF(lst1,lst2,lst3):
    lst4=diff(intersection(lst1,lst2),lst3)
    return lst4



SEComp = []
n = int(input("\nEnter number of students in SE COMP: "))
print("Enter the names of",n,"students :")
for i in range(0, n):
    element = input()
    SEComp.append(element) 
print("Original list of students in SEComp : " + str(SEComp))

Cricket = []
n = int(input("Enter number of students who play cricket : "))
print("Enter the names of",n,"students who play cricket : ")
for i in range(0, n):
    element = input()
    Cricket.append(element)  
print("Original list of students playing cricket is :" +str(Cricket))
Cricket=removeDuplicate(Cricket)
print("The list of students playing cricket after removing duplicates : " +str(Cricket))

Badminton = []
n = int(input("Enter number of students who play badminton : "))
print("Enter the names of",n,"students who play badminton : ")
for i in range(0, n):
    element = input()
    Badminton.append(element)  
print("Original list of students playing badminton is :" +str(Badminton))
Badminton=removeDuplicate(Badminton)
print("The list of students playing badminton after removing duplicates : " +str(Badminton))

Football = []
n = int(input("Enter number of students who play football : "))
print("Enter the names of",n,"students who play football : ")
for i in range(0, n):
    element = input()
    Football.append(element)  
print("Original list of students playing football is :" +str(Football))
Football=removeDuplicate(Football)
print("The list of students playing football after removing duplicates : " +str(Football))

print("The students who play both cricket and badminton are : ", intersection(Cricket,Badminton))
print("The students who play cricket or badminton but not both are : ", sym_diff(Cricket,Badminton) )
print("The students who play neither cricket nor badminton are : ", nCnB(SEComp,Cricket,Badminton))
print("The students who play cricket and football but not badminton are : ", CBnF(Cricket,Football,Badminton))
