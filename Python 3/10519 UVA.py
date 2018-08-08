import sys

#sys.stdin = open("py_in.txt","r")
#sys.stdout = open("py_out.txt","w")

if __name__ == "__main__":
    while (True):
        try:
            n = int(input())
            answer = n**2 - n + 2
            if(n==0):   answer = 1
            print(answer)
        except:         break
