def Binary_Search(lst, key):
    left, right=0, len(lst)-1
    while left<=right:
        mid=(left+right)//2
        if lst[mid]==key:
            return mid
        elif lst[mid]<key:
            left=mid+1
        else:
            right=mid+1
    return -1

def fibonacci_search(arr, target):
    n = len(arr)
    
    fib_m_minus_2 = 0
    fib_m_minus_1 = 1
    fib = fib_m_minus_1 + fib_m_minus_2
    
    while (fib < n):
        fib_m_minus_2 = fib_m_minus_1
        fib_m_minus_1 = fib
        fib = fib_m_minus_1 + fib_m_minus_2
    
    offset = -1
    
    while (fib > 1):
        i = min(offset + fib_m_minus_2, n - 1)
        
        if (arr[i] < target):
            fib = fib_m_minus_1
            fib_m_minus_1 = fib_m_minus_2
            fib_m_minus_2 = fib - fib_m_minus_1
            offset = i
        
        elif (arr[i] > target):
            fib = fib_m_minus_2
            fib_m_minus_1 = fib_m_minus_1 - fib_m_minus_2
            fib_m_minus_2 = fib - fib_m_minus_1
        
        else:
            return i
    
    if (fib_m_minus_1 and arr[offset + 1] == target):
        return offset + 1
    
    return -1

arr=[12, 15, 5, 7, 19, 17, 24, 34, 25]
key=34
print("Student found at position", Binary_Search(arr, key), "(Binary Search)")
print("Student found at position", fibonacci_search(arr, key), "(Fibonacci Search)")
