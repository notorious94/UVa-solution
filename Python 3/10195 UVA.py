import math

#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

while True:
    try:
        a,b,c = map(float,input().split())
        s = (a+b+c) / 2.0
        if s == 0.0:
            print("The radius of the round table is: 0.000")
        else:
            area = math.sqrt(s*(s-a)*(s-b)*(s-c))
            r = area / s
            print("The radius of the round table is: {0:0.3f}".format(r))
    except:
        break
