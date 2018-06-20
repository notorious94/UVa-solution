import sys

#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

test = int(input())
for case in range(test):
    n = int(input())
    if(n<=1):
        print(n)
        continue
    d = False
    result = ""
    while(n!=1):
        d = False
        i = 9
        while(i>=2):
            if(n%i==0):
                d = True
                result += chr(48+i)
                n//=i
                break
            i-=1
        if(d==False):
            break
    if(d==False):
        print("-1")
    else:
        print(result[::-1])
