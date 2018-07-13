import sys
#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

self = [True] * 1000001

def generate_self():
    for i in range(1,1000001):
        if self[i]==True:
            n = i
            while True:
                sum = n
                while (n!=0):
                    sum+=n%10
                    n//=10
                n = sum
                if(n<=1000000 and self[n]==True):
                    self[n] = False
                else:   break

generate_self()

for i in range (1,1000001):
    if(self[i]==True):
        print(i)
