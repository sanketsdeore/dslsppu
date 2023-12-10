def Selection_Sort(marks):
  for i in range(len(marks)):
    min_idx=i;
    for j in range(i+1, len(marks)):
      if (marks[min_idx]>marks[j]):
        min_idx=j
    marks[i], marks[min_idx]=marks[min_idx], marks[i];
  print("Marks of students after Selection Sort: ", marks)

def Bubble_Sort(marks):
    for j in range(len(marks)):
        for i in range(len(marks)-1):
            if (marks[i]>marks[i+1]):
                marks[i], marks[i+1]=marks[i+1], marks[i];
    print("Marks of students after Bubble Sort: ", marks)
    
def partition(marks, start, end):
    pivot=marks[start];
    i=start+1;
    j=end;
    
    while True:
        while i<=j and marks[i]<=pivot:
            i+=1;
        while i<=j and marks[j]>=pivot:
            j-=1;
        if i<=j:
            marks[i], marks[j]=marks[j], marks[i];
        else:
            break;
    marks[start], marks[j]=marks[j], marks[start];
    return j;

def Quick_Sort(marks, start, end):
    if start<=end:
        part=partition(marks, start, end);
        Quick_Sort(marks, start, part-1);
        Quick_Sort(marks, part+1, end);
    return marks;
