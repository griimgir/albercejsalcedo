import sys
sys.setrecursionlimit(100000)

def factorial(n):
    # Provide your code here
    if(n == 0):
        return 1
    else:
        return n*factorial(n-1)
        
print "factorial(5):", factorial(5)
# Expected 120

def fib(n):
    # Provide your code here
    if(n == 0):
        return 0
    elif(n == 1):
        return 1
    else:
        return fib(n-1) + fib(n-2)

def equal(A, B):
    # Provide your code here
    if (len(A) == 0):
        return len(B) == 0
    if (len(B) == 0):
        return len(A) == 0
    else:
        return A[0] == B[0] and equal (A[1:], B[1:])
    
print "equal('ALICE', 'BOB):", equal('ALICE', 'BOB')
# Expected False
print "equal('ALICE', 'ALICE'):", equal('ALICE', 'ALICE')
# Expected True

def addup(list):
    # Provide your code here
    if (len(list) == 0):
        return 0
    else:
        return list[0] + addup(list[1:])

print "addup([1,2,3,4,5]):", addup([1,2,3,4,5])
# Expected 15
print "addup(range(101)):", addup(range(101))
# Expected 5050

def reverse(A):
    # Provide your code here
        if len(A) == 1:
            return A
        else:
            return A[-1] + reverse(A[:-1])
print "reverse('hello'):", reverse('hello')
# Expected olleh

def isSorted(list):
    # Provide your code here
    if (len(list)) == 1:
        return True
    else:
        return list[0] < list[1] and isSorted(list[1:])

print "isSorted([1,2,3,4]):", isSorted([1,2,3,4])
# Expected True
print "isSorted([1,22,3,4]):", isSorted([1,22,3,4])
# Expected False

def linearSearch(A, value):
    # Provide your code here
    if (len(A) == 0):
        return False
    else:
        return (A[0] == value) or (linearSearch(A[1:], value))
        
print "linearSearch([1, 2, 3, 4, 5], 4):", linearSearch([1, 2, 3, 4, 5], 4)
# Expected True
print "linearSearch(range(900), -1):", linearSearch(range(900), -1)
# Expected False

def binarySearch(A, value):
    # Provide your code here
    if (len(A) == 0):
        return False

    mid = len(A)/2

    if (value == A[mid]):
        return True
    elif (value > A[mid]):
        return binarySearch(A[mid:], value)
    else:
        return binarySearch(A[:mid], value)
            
print "binarySearch([1, 2, 3, 4, 5], 4):", binarySearch([1, 2, 3, 4, 5], 4)
# Expected True
print "binarySearch(range(1000000), -1):", binarySearch(range(1000000), -1)
# Expected False