def phi(n):
    result = n
    i = 2
    while i*i<=n:
        if(n%i==0):
            while(n%i==0):
                n //= i
            result -= (result//i)
        i += 1
    if n>1:
        result-= result//n
    return result

while 1:
    n = int(input())
    if(n==0):   break
    print(phi(n))
