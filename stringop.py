def longest(a):
    a=a.split()
    temp=a[0]
    max=len(a[0])
    
    for i in range(len(a)):
        if len(a[i])>max:
            temp=a[i]
            max=len(temp)
    print("The longest word is", temp, "with", max, "characters.")

def occurence(a, char):
    count=0
    for i in a:
        if i==char:
            count+=1
    print(char, "occurs", count, "times.")

def palindrome(a):
    for i in range(int(len(a)/2)):
        if a[i]!=a[len(a)-i-1]:
            return False
    return True

def substr(mainstr, sub):
    res = []
    for i in range(len(mainstr)):
        k = i
        flag = 0
        for j in range(len(sub)):
            if mainstr[k] == sub[j]:
                flag = 1
            else:
                flag = 0
                break
            k = k + 1
        if flag:
            res.append(i)
    print(sub, "found at", res)
    

lst="I know three programming languages."
longest(lst)

word="malayalam"
occurence(word, 'a')
print(palindrome(word))

main_string = "ababcababcabc"
substring = "abc"
substr(main_string, substring)
