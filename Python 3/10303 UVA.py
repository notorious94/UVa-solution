T = [None]*1010
T[0] = T[1] = 1

for i in range(2,1001):
    T[i] = 0
    for j in range(0,i):
        T[i] = T[i]+(T[j]*T[i-j-1])

while True:
    try:
        n = int(input())
        print(T[n])
    except:
        break;
