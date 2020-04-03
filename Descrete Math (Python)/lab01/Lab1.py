from logic import TruthTable

myTable = TruthTable(['p', 'q'], ['-p'])
myTable.display()

myTable = TruthTable(['p', 'q'], ['p and q'])
myTable.display()

myTable = TruthTable(['p', 'q'], ['p -> q'])
myTable.display()

myTable = TruthTable(['p', 'q'], ['p or q'])
myTable.display()

myTable = TruthTable(['p', 'q'], ['p -> q'])
myTable.display()

myTable = TruthTable(['p', 'q'], ['p <-> q'])
myTable.display()

print myTable.table

print '--------------------------------------------------'

myTable.latex()

print '--------------------------------------------------'

