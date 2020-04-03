# You are not allowed to import any modules whatsoever

# Assume a set is represented as a Python list

# Do not modify these
A = [1, 2, 5, 8, 12, 5]
B = [3, 5, 7, 8, 11, 3]



# Define a function that takes in a set, represented as a Python list, 
# and returns an equivalent set with all duplicates removed
def simplify(A):
    # Provide your code here...
    result = []
    for i in A:
        if i not in result:
            result.append(i)
    return result
    
# Testing the simplify function
print "A = ", simplify(A)
print "B = ", simplify(B)

# Expected:
# A =  [1, 2, 5, 8, 12]
# B =  [3, 5, 7, 8, 11]

print



# Define a function that takes in two sets and returns their union.
# The resulting set should be a Python list with no duplicates
def union(A, B):
    # Provide your code here...
    result = []
    for i in A+B:
        if i not in result:
            result.append(i)
    return result
    
# Testing the union function    
print "A union B = ", union(A, B)

# Expected:
# A union B =  [1, 2, 5, 8, 12, 3, 7, 11]

print



# Define a function that takes in two sets and returns their intersection.
# The resulting set should be a Python list with no duplicates
def intersection(A, B):
    # Provide your code here...
    result = []
    SB = simplify(B)
    for i in simplify(A):
        if i in SB:
            result.append(i)
    return result   
    
    
# Testing the intersection function    
print "A intersection B = ", intersection(A, B)

# Expected:
# A intersection B =  [5, 8]

print



# Define a function that takes in two sets, A and B, and returns True 
# if A is a subset of B, and False otherwise
def subset(A, B):
    # Provide your code here...
    result = True
    for i in A:
        if i not in B:
            result = False
    return result
    
# Testing the subset function   
print "A subset of B:", subset(A, B) 
print "[5, 7, 8] subset of B:", subset([5,7,8], B)

# Expected:
# A subset of B: False
# [5, 7, 8] subset of B: True

print



# Define a function that takes in two sets and returns True
# if they are equal, and False otherwise
def equal(A, B):
    # Provide your code here...
    return subset(A,B) and subset(B,A)
    
# Testing the equal function
print "A == B:", equal(A, B)
print "[1, 2, 3, 4] == [1, 1, 2, 2, 4, 2, 3, 3]:", equal([1, 2, 3, 4],[1, 1, 2, 2, 4, 2, 3, 3])

# Expected:
# A == B: False
# [1, 2, 3, 4] == [1, 1, 2, 2, 4, 2, 3, 3]: True

print



# Define a function that takes in two sets and returns their Cartesian product
# The result should be represented as a list of tuples, ex: [(1, 1), (1, 2), ...]
def cartesian_product(A, B):
    # Provide your code here...
    result = []
    SB = simplify(B)
    for i in simplify(A):
        for j in SB:
            result.append((i, j))
    return result

# Testing the cartesian_product function
print "[1] x B =", cartesian_product([1], B)
print "[1, 2] x B =", cartesian_product([1, 2], B)
print "[] x B =", cartesian_product([], B)

# Expected:
# [1] x B =  [(1, 3), (1, 5), (1, 7), (1, 8), (1, 11)]
# [1, 2] x B =  [(1, 3), (1, 5), (1, 7), (1, 8), (1, 11), (2, 3), (2, 5), (2, 7), (2, 8), (2, 11)]
# [] x B =  []

print



# Define a function that takes in a set and returns its power set
# The result should be represented as a list of lists, ex: [[], [1], [2], [1, 2]]
def power_set(A):
    # Provide your code here...
    #A = [1, 2, 3]
    #power_set(A) = [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
    if len(A) == 0:
        return [[]]
    else:
        head = A[0:-1]
        last = A [-1]
        temp = power_set(head)
        result = temp[:]
        for i in temp:
                result.append(i + [last])
        return result

# Testing the power_set function        
print "P([1, 2, 3]) =", power_set([1, 2, 3])
print "P([]) =", power_set([])

# Expected:
# P([1, 2, 3]) =  [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]]
# P([]) = [[]]
