# Factorial Loop
Fact = []
Fact.append(-1)
f = 1
for i in range(1,301):
    f = f*i
    Fact.append(f)

# Catalan Loop
C = []
C.append(1)
C.append(1)

for i in range(2,301):
    C.append(0)
    for j in range(0,i):
        C[i] = C[i]+(C[i]*C[i-j-1])

#Final Result
for i in range(1,301):
    C[i] = C[i]*Fact[i]

#Input Loop
while True:
    try:
        n = int(input())
        print(C[n])
    except:
        break
