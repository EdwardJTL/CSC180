def fibo(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    else:
        return fibo(n-1)+fibo(n-2)

def fiboL(n):
    L=[]
    for i in range(0,n+1,1):
        L.append(fibo(i))
    return L

def product(x,y):
    return x*y

def redfibo(n):
    if n == 0:
        return 1
    if n>=1:
        return reduce(product,fiboL(n))