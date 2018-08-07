import sys

#sys.stdin = open("py_in.txt","r")
#sys.stdout = open("py_out.txt","w")

lp = [0]*46341
prime = []
def sieve():
    for i in range(2,46341):
        if(lp[i]==0):
            lp[i] =  i
            prime.append(i)
        j = 0
        while(j<len(prime) and i*prime[j]<46341 and prime[j]<=i):
            lp[i*prime[j]] = i
            j+=1

sieve()

def isPrime(N):
    if(N==1):    return True;
    if(N<46341): return (lp[N]==N)
    r = N**0.5
    r = int(r)
    i = 0
    while(i<len(prime) and prime[i]<=r):
        if (N % prime[i] == 0):   return False
        i+=1
    return True

while(True):
    n = int(input())
    if(n==0):   break
    N = 2**n - 1
    if(isPrime(N)):
        perfect = N * 2**(n-1)
        print("Perfect: ",perfect,"!",sep="")
    elif(n==11 or n==23 or n==29):
        print("Given number is prime. But, NO perfect number is available.")
    else:
        print("Given number is NOT prime! NO perfect number is available.")
