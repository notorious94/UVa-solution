fib = []
fib.append(0)
fib.append(1)

for a in range(2,5001):
    fib.append(a)

for a in range(2,5001):
    fib[a] = fib[a-1] + fib[a-2]

while(True):
    try:
        n = int(input())
        print('The Fibonacci number for',n,'is',fib[n])
    except:
        break;
