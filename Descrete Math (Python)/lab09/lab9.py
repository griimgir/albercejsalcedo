# Exercise 1: Implement Euclid's Algorithm for finding the greatest common divisor of two integers
def gcd(a, b):
    x = a
    y = b
    while y != 0:
        r = x % y
        x = y
        y = r
    # Provide the correct implementation
    return x

print gcd(128, 60)
# Expected output: 4



# Exercise 2: Consider the following representation of mathematical expressions: a list of tuples, 
# where each tuple has exactly 2 elements, a coefficient and a term. For example, the expression:


# 2x + 5y - 3z is represented as [(2, x), (5, y), (-3, z)]

# We sometimes need to simplify expressions by grouping together like terms. For example:

# 2x + 5y + 4x = 6x + 5y

# Implement the function groupLikeTerms, where the input exp is a mathematical expression represented as a list of tuples, and it should return a simplified mathematical expression represented as a list of tuples.
def groupLikeTerms(exp):
    list =[]
    for i in exp:
        if i[1] not in list:
            list.append(i[1])
    result = []
    for t in list:
        c = 0
        for i in exp:
            if i[1] == t:
                c = c + i[0]
        result.append((c, t))
    # Provide the correct implementation
    return result
    
print groupLikeTerms([(5, "x"), (5, "y"), (-3, "x")])
# Expected output: [(2, 'x'), (5, 'y')]


    
# Exercise 3: We sometimes need to substitute expressions into other expressions. For example if we 
# ave the expression 2x + 5y, and we know that x = 3a - b, we can substitute the expression for x into 
# the original expression, resulting in: 6a - 2b + 5y.

# Implement the substitution function below. It should take an expression (list of tuples), a term, and 
# another expression. It should substitute the occurences of term in exp, with value. The result 
# should be in its simplest form, i.e. like terms should be grouped together 

# For example: substitute([(2, 5), (-1, 9)], 5, [(1, 23), (-2, 9)]) results in [(-5, 9), (2, 23)]
def substitute(exp, term, value):
    # Provide the correct implementation
    for i in exp:
        if i[1] == term:
            coeff = i[0]
            exp.remove(i)
            for j in value:
                exp.append((coeff*j[0], j[1]))
            break
    return groupLikeTerms(exp)
            
print substitute([(2, 5), (-1, 9)], 5, [(1, 23), (-2, 9)])
# Expected output: [(-5, 9), (2, 23)]



# Exercise 4: Using the functions you implemented above, implement the Extended Euclidean Algorithm, which returns the GCD of two integers a, and b, as a linear combination of a and b.

# For example: extended_euclid(101, 23) results in (1, [(22, 23), (-5, 101)]), where the GCD is 1 and it can be expressed as 22*23 - 5*101
def extended_euclid(a, b):
    # Provide the correct implementation
    x = a
    y = b
    lines = []

    while y != 0:
        r =x % y

        if r != 0:
            lines.insert(0, (r, [(1, x), (-(x/y), y)]))

        x = y
        y = r

    ans = lines[0][1]

    for line in lines[1:]:
        term = line[0]
        value = line [1]
        ans = substitute(ans, term, value)

    return x, ans

print extended_euclid(101, 23)
# Expected output: (1, [(22, 23), (-5, 101)])



# Exercise 5: Use the Extended Euclidean Algorithm to implement the function for multiplicative inverses. 
# As you know, a multiplicative inverse n modulo m is guaranteed to exist if n and m are relatively prime. 
# If they are not, your algorithm should return None (which is the null value of Python), otherwise, 
# if n and m are relatively prime, you should return the inverse of n modulo m.
def inverse(n, m):
    r = extended_euclid(n, m)

    if r[0] == 1:
        for i in r[1]:
            if i[1] == n:
                ans = i[0]
                if ans < 0:
                    ans = ans + m
                return ans
    else:
        return None
    # Provide the correct implementation
    
print inverse(23, 101)
# Expected output: 22
