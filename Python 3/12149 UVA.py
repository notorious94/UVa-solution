import sys

#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

while True:
    n = int(input())
    if(n==0):
        break
    ans = 0
    for i in range(1,n+1):
        ans += i*i
    print(ans)
