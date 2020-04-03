from logic import TruthTable

cont = 'Y'
prop = []
while cont == 'Y':
    a = raw_input("Enter a proposition: ")
    prop.append(a)
    cont = raw_input("Would you like to enter more (Y/N): ")

myTable = TruthTable(prop)

print 'Your program uses propositional variables ',myTable.vars
#print '------------------------'
#print myTable.table
#print '------------------------'

inside = myTable.vars
props = []
i = 0
while i < len(inside):
    props.append(raw_input("Enter meaning of "+ inside[i] +': '))
    i+=1

v = []
for i in myTable.table:
    v.append(i[1])
for r in v:
    if(r[2] == 1):
        print 'Your description is consistent when:'
        print 'It is not the case when', props[0]
        print 'It is not the case when', props[1]
        break
    else:
        print 'Your description is inconsistent'
        print 'It is the case when', props[0]
        print 'It is the case when', props[1]
        break














#v = []
#props = []
#increment = 0
#counter = 0
#if (myTable.vars == ['p', 'q']):
#    for j in ['p', 'q']:
#        if (j[0] == 'p'):
#            props[0] = j[0]
#        elif (j[1] == 'q'):
#            props[1] = j[1]
#        else:
#            break
#else:
#    print 'Your variables are not supported in logic.py'
#
#for k in props :
#    props[0] = raw_input("Give a meaning p")
#    props[1] = raw_input("Give a meaning to q")
#
#for i in myTable.table:
#    v.append(i[1])
#for r in v:
#    if (r[0] == r[1]):
#        if(r[1] == 0):
#            print 'Your description is consistent'
#            break
#    else:
#        print 'Your description is inconsistent'
#        break

#v =[]
#for i in myTable.table:
#    v.append(i[1])
#for r in v:
    #print r[1]
    #print 'a'
    #print '--------'
    #print r[0]
    #print 'b'
    #print '--------'
    #if (r[0] == r[1]):
        #if(r[0] == 0):
        #print 'Your description is consistent'
            
    #else:
        #print 'Your description is inconsistent'