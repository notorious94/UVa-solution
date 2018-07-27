while True:
    a,b,c,d = input().split(" ")
    a = int(a)
    b = int(b)
    c = int(c)
    d = int(d)

    if(a+b+c+d==0): break
    angle = 720+360
    if(b>a): angle+=(40-b+a)*9
    else:    angle+=(a-b)*9
    if(c>=b): angle+=(c-b)*9
    else:    angle+=(40-b+c)*9
    if(d>c): angle+=(40-d+c)*9
    else:    angle+=(c-d)*9
    print(angle)
