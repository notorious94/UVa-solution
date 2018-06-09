import sys,queue

#sys.stdin = open("in.txt","r")
#sys.stdout = open("out.txt","w")

aList = [[] for v in range(100001)]
visit = [False] * 100000
level = [0] * 100000

test = int(input())

def reset(v):
    for i in range(v):
        visit[i] = False
        aList[i].clear()

def BFS(s,d):
    visit[s] = True
    level[s] = 0
    q = queue.Queue()
    q.put(s)
    while q.empty() == False:
        u = q.get()
        for i in range (len(aList[u])):
            v = aList[u][i]
            if(visit[v]==False):
                visit[v] = True
                level[v] = level[u]+1
                q.put(v)
        if(visit[d]):
            return level[d]-1

for case in range(test):

    empty_line = input()

    v = int(input())
    reset(v)

    for i in range (v):
        edge = map(int,input().split())
        n = 0
        for e in edge:
            n += 1
            if(n<=2):   continue
            else:   aList[i].append(e)

    s,d = map(int,input().split())
    print(s,d,BFS(s,d))
    if(case!=test-1):
        print()
