import sys

#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

case = 1
while True:
    N = int(input())
    if(N==0):   break
    N = (((8.0*N+9.0)**0.5)+3.0)/2.0
    n = int(N)
    if(n != N): n+=1
    print("Case ",case,": ",n,sep="")
    case+=1
