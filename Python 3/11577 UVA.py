import sys

#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

if __name__=='__main__':
    freq = [None] * 27
    test = int(input())
    for case in range (test):
        max_freq = 0

        for i in range(27):
            freq[i] = 0

        string = input()
        string = string.lower()

        for i in range(len(string)):
            if(string[i]>='a' and string[i]<='z'):
                loc = ord(string[i])-ord('a')
                freq[loc]+=1
                if(freq[loc]>max_freq):
                    max_freq = freq[loc]

        for i in range(27):
            if(freq[i]==max_freq):
                print(chr(i+ord('a')),end="")
        print("")
