#Enter proposition 1: p and q
#Enter proposition 2: q and p
#The propositions are equivalent


from logic import TruthTable

prop1 = raw_input("Enter an proposition 1: ")
prop2 = raw_input("Enter proposition 2: ")

myTable = TruthTable(['p', 'q'], [prop1])
myTable2 = TruthTable(['p', 'q'], [prop2])


print myTable.table
print myTable2.table


if (myTable.table == myTable2.table):
    print 'The propositions are equal.'
else:
    print 'These propositions are not equal.'


print '--------------------------------------------------'

myTable.latex()

print '--------------------------------------------------'