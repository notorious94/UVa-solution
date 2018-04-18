import sys

#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

while True:
    n = int(input())
    if n==0 : break
    bottle = 0
    while n>=3:
        bottle = bottle + int(n/3)
        n = int(n/3)+int(n%3)
        if n==2 : n = 3
    print(int(bottle))
