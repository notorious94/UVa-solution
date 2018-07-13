import sys
#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

prime = [0] * 1299710
pr = []
def sieve():
    for i in range(2,1299710):
        if(prime[i]==0):
            prime[i] = i
            pr.append(i)
        j = 0
        while(j<len(pr) and i*pr[j]<1299710 and pr[j]<=i):
            prime[i*pr[j]] = i
            j+=1
    prime[1] = 2
    for i in range(len(pr)-1):
        a = pr[i]
        b = pr[i+1]
        diff = b - a
        prime[a] = prime[b] = 0
        for j in range(a+1,b):
            prime[j] = diff

sieve()

while(True):
    n = int(input())
    if(n==0):
        break
    print(prime[n])
