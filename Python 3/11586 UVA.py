test = int(input())
for case in range(test):
    train = input()
    male = female = 0
    for i in range (len(train)):
        if(train[i]=='M'):  male+=1
        elif (train[i] == 'F'):  female += 1
    if(male==female and male != 1):
        print("LOOP")
    else:
        print("NO LOOP")
