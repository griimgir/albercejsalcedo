from logic import TruthTable
cont = 'Y'
prop = []
while cont == 'Y':
    a = raw_input("Enter a proposition: ")
    prop.append(a)
    cont = raw_input("Would you like to enter more (Y/N): ")
#print prop
myTable = TruthTable(prop)
#print myTable.table

print myTable.vars

v = []
for i in myTable.table:
    v.append(i[1])
for r in v:
    if (r[0] == r[1]):
        if(r[1] == 0):
            print 'Your description is consistent'
            break
    else:
        print 'Your description is inconsistent'
        break
