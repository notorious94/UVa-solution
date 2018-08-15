import sys

#sys.stdin = open("py_in.txt","r")
#sys.stdout = open("py_out.txt","w")

lp = [0]*10001
prime = []

def sieve():
    for i in range(2,10001):
        if(lp[i]==0):
            lp[i] = i
            prime.append(i)
        j = 0
        while(j<len(prime) and i*prime[j]<10001 and prime[j]<=i):
            lp[prime[j]*i] = i
            j+=1

if __name__ == "__main__":

    sieve()
    t = int(input())

    for case in range(t):
        n = int(input())
        max_diff = -0
        X = 0
        i = len(prime) - 1
        while(i>=0):
            if(prime[i]<=n):
                p = n//prime[i]
                x = prime[i]
                if(p*x<=n and n<(p+1)*x):
                    if(n-p*x>max_diff):
                        max_diff = n - p*x
                        X = x
            i-=1
        print(X)
