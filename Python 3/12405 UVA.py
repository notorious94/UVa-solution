test = int(input())

for case in range (test):
    n = int(input())
    f = input()
    F = []
    for char in f:
        F.append(char)

    scareCrow = 0
    for i in range (n):
        if(F[i]=='.'):
            if(i+2<n):
                scareCrow+=1
                F[i]=F[i+1]=F[i+2]='#'
            elif (i+1<n):
                F[i] = F[i+1] = '#'
                scareCrow+=1
            else:
                scareCrow+=1

    print("Case ",case+1,": ",scareCrow,sep="")
