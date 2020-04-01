v = []
n = int(input("Numarul de elemente din vector:"))

for i in range (n):
    v.append(int(input("Dati elementul "+str(i)+": ")))

def bubble(v):
    bol = True
    while bol:
        bol = False
        for i in range(len(v)-1):
            if v[i]>v[i+1]:
                aux = v[i]
                v[i]=v[i+1]
                v[i+1] = aux
                bol = True
    return v

def insert_sort(v):
    i = 1
    while i <= len(v) - 1:
        val = v[i]
        j = i - 1
        while j >= 0 and v[j] > val:
            v[j + 1] = v[j]
            j = j - 1
        v[j + 1] = val
        i = i + 1
    return v

def merge_sort(v):
    vsortat = []
    if len(v) < 2:
        return v
    mid = int(len(v)/2)
    y = merge_sort(v[:mid])
    z = merge_sort(v[mid:])
    while (len(y) > 0) or (len(z) > 0):
        if len(y) > 0 and len(z) > 0:
            if y[0] > z[0]:
                vsortat.append(z[0])
                z.pop(0)
            else:
                vsortat.append(y[0])
                y.pop(0)
        elif len(z) > 0:
            for i in z:
                vsortat.append(i)
                z.pop(0)
        else:
            for i in y:
                vsortat.append(i)
                y.pop(0)
    return vsortat

def shell_sort(arr):
    n = len(arr)
    gap = n//2
    while gap > 0:
        for i in range(gap,n):
            temp = arr[i]
            j = i
            while  j >= gap and arr[j-gap] >temp:
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr


def partition(arr, low, high):
    i = (low - 1)  # index of smaller element
    pivot = arr[high]  # pivot

    for j in range( low, high ):

        # If current element is smaller than or
        # equal to pivot
        if arr[j] <= pivot:
            # increment index of smaller element
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)

def quick_sort(arr, low, high):
    if low < high:
        pi = partition( arr, low, high )

        quick_sort( arr, low, pi - 1 )
        quick_sort( arr, pi + 1, high )


print("Alege o metoda de sortare: \n 1 pentru Bubble sort, \n 2 pentru Insert sort, \n 3 pentru Merge sort, \n 4 pentru Shell sort, \n 5 pentru Quick sort")
r = int(input("Ce alegi?"))
if r ==1:
       print(bubble(v))
elif r==2:
    print(insert_sort(v))
elif r==3:
    print(merge_sort(v))
elif r==4:
    print(shell_sort(v))
elif r==5:
    quick_sort(v,0,n-1)
    print(v)
else:
    print('Nu ai citi corect varianta dorita')
