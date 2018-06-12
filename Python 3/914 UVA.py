import bisect
import sys

#sys.stdin  = open("in.txt" ,"r")
#sys.stdout = open("out.txt","w")

p = [0] * 1000001
prime = []

def sieve():
    for i in range(2,1000001):
        if(p[i]==0):
            p[i] = i
            prime.append(i)
        j = 0
        while(j<len(prime) and i*prime[j]<=1000000 and prime[j]<=i):
            p[i*prime[j]] = prime[j]
            j+=1

if __name__ == '__main__':

    sieve()

    test = int(input())

    for case in range(test):

        l,u = map(int,input().split())

        li = bisect.bisect_left(prime,l)

        if(li==len(prime)):
            print("No jumping champion")
            continue

        i = li
        j = li+1
        freq = [0]*1000001
        max_freq = 0
        ans = []

        while(j<len(prime) and prime[j]<=u):
            diff = prime[j]-prime[i]
            j+=1
            i+=1
            freq[diff]+=1
            if(freq[diff]>max_freq):
                ans.clear()
                max_freq = freq[diff]
                ans.append(diff)
            elif(freq[diff]==max_freq):
                ans.append(diff)

        if(max_freq==0 or len(ans)>1):
            print("No jumping champion")
        else:
            print("The jumping champion is",ans[0])
