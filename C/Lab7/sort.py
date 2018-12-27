def bubbleSort(array):
    n = len(array)
    swapping = True
    try:
        while swapping == True:
            swapped = False
            for i in range(1,n,1):
                if array[i-1] > array[i]:
                    temp = array[i-1]
                    array[i-1] = array[i]
                    array[i] = temp
                    swapped = True
            n = n-1
            if not swapped:
                swapping = False
        return [True, array]
    except:
        return False
