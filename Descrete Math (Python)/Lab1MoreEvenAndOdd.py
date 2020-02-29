n2 = 0
even = 0
for i in range(10):
    n1 = int (input("Enter an number: "))
    #odd or even condition n1%2 != 0
    if(n1%2!=0):
        if(n1>n2):
            n2 = n1
    else:
        even = even + 1
if(even == 10):
    print("No odds found")
else:
    print(n2)





    

