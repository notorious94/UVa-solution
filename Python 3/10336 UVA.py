import sys
import queue
import operator

#sys.stdin  = open("in.txt","r")
#sys.stdout = open("out.txt","w")

grid = []
r,c = 0,0
dx = [0,0,1,-1,-1,1,-1,1]
dy = [-1,1,0,0,1,1,-1,-1]

def reset():
    grid.clear()

def inBound(x,y):
    return(x>=0 and x<r and y>=0 and y<c)

def BFS(x,y):
    character = grid[x][y]
    grid[x][y] = '.'
    q1 = queue.Queue()
    q2 = queue.Queue()
    q1.put(x)
    q2.put(y)
    while(q1.empty()==False):
        ux = q1.get()
        uy = q2.get()
        for i in range(4):
            vx = ux + dx[i]
            vy = uy + dy[i]
            if(inBound(vx,vy) and grid[vx][vy]==character):
                grid[vx][vy] = '.'
                q1.put(vx)
                q2.put(vy)

test = int(input())

for case in range(test):
    reset()
    alpha_set = [0] * 26
    r,c = map(int,input().split())
    for i in range(r):
        s = input()
        grid.append([])
        for j in range(len(s)):
            grid[i].append(s[j])

    for i in range(r):
        for j in range(c):
            if(grid[i][j]!='.'):
                alpha_set[ord(grid[i][j])-ord('a')]+=1
                BFS(i, j)

    print("World #",case+1,sep="")
    result = []
    for i in range(26):
        if(alpha_set[i]!=0):
            c = chr(ord('a')+i)
            result.append([c,alpha_set[i]])
    result.sort(key = lambda n: (n[1]*-1,n[0]))
    for i in range(len(result)):
        print(result[i][0],": ",result[i][1],sep="")
