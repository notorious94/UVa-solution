
Factorial = [None] * 21
f = 1
for i in range(1,21):
    f = f * i
    Factorial[i] = f

freq = [None] * 26

test = int(input())
for t in range(1,test+1):
    s = input()
    for i in range(26):
        freq[i] = 0

    for i in range(len(s)):
        freq[ord(s[i])-ord('A')] = freq[ord(s[i])-ord('A')] + 1

    result = Factorial[len(s)]

    for i in range(26):
        if(freq[i]!=0):
            result = result / Factorial[freq[i]]
    print("Data set ",t,": ",int(result),sep="")
