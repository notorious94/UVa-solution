import sys

#sys.stdin = open("py_in.txt","r")
#sys.stdout = open("py_out.txt","w")

while True:

    au,ad = input().split(" ")

    au = int(au)
    ad = int(ad)

    if(au==1 and ad==1):    break

    lu = rd = 0
    ld = ru = 1

    while(True):
        mu = lu+ru
        md = ld+rd
        if(mu==au and md==ad):
            print()
            break
        if((mu/md)>(au/ad)):
            ru = mu
            rd = md
            print("L",end="")
        else:
            lu = mu
            ld = md
            print("R", end="")
