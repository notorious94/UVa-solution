import sys

#sys.stdin = open("py_in.txt","r")

n = int (input())
dream = []
for test in range(n):
    choice = input()
    if(choice[0]=='S'):
        command,name = choice.split(" ")
        dream.append(name)
    elif(choice[0]=='T'):
        if(len(dream)==0):
            print("Not in a dream")
        else:
            print(dream[-1])
    else:
        if(len(dream)):
            dream.pop()
