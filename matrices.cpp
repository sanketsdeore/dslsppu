row=int(input("Number of rows: "))
col=int(input("Number of columns: "))

m1=[[0 for i in range(col)] for i in range(row)]
m2=[[0 for i in range(col)] for i in range(row)]
ans=[[0 for i in range(col)] for i in range(row)]

for n in range(2):
    print(f"\nEnter data for matrix {n+1}: ")
    if(n==0):
        matrix=m1
    else:
        matrix=m2
    for i in range(row):
        for j in range(col):
            matrix[i][j]=int(input(f"Enter value for row {i+1} and column {j+1}: "))

for i in range(row):
    for j in range(col):
        ans[i][j]=m1[i][j]+m2[i][j]
print("Addition: ", ans)

for i in range(row):
    for j in range(col):
        ans[i][j]=m1[i][j]-m2[i][j]
print("Subtraction: ", ans)

def transpose(m):
    T=[[0 for i in range(row)] for i in range(col)]
    for i in range(row):
        for j in range(col):
            T[i][j]=m[j][i]
    return (T)
print("Transpose Matrix 1: ", transpose(m1))
print("Transpose Matrix 2: ", transpose(m2))

for i in range(row):
    for j in range(col):
        for k in range(len(m2)):
            ans[i][j]+=m1[i][k]*m2[k][j]
print("Multiplication: ",ans)
