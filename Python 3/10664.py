import sys

#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

test = int(input())

for case in range(test):
    line = map(int,input().split())
    weights = []
    cap = [0] * 400
    sum = 0
    for l in line:
        sum+=l
        weights.append(l)
    if(sum%2==1):
        print("NO")
        continue
    sum//=2
    for i in range(0,sum+1):
        cap[i] = 0

    for i in range(len(weights)):
        j = sum
        while(j>0):
            if(weights[i]<=j):
                cap[j] = max(cap[j],weights[i]+cap[j-weights[i]])
            j-=1

    if(cap[sum]==int(sum)):
        print("YES")
    else:
        print("NO")
