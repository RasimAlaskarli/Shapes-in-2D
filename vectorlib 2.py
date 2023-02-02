


from pickletools import read_uint1


def scalar_mult(sc,v):
    """


    >>> scalar_mult(7,[-1,3])
    [-7, 21]

    """
    #Here we create a new list and add the numbers from vector v multiplied by sc
    newlist = list()
    for item in v:

        newlist.append(item*sc)

    return newlist

def dot_product(u,v):
    """
    >>> dot_product([8,0], [3,6])
    24
    """
    #variable that counts the sum of the multiplication of elements
    sum = 0
    if len(u) != len(v):
        return None
    for index in range(0, len(u)):
        sum = sum + u[index] * v[index]
    return sum

def cross_product(u,v):
    """
    >>> cross_product([1,3,4],[2,7,-5])
    [-43, -13, 1]
    """
    newList = list()
    #the lengths should be 3, otherwise it does not work
    if len(u) != 3 or len(v) != 3:
        return None
    
    newList.append(u[1]*v[2]-u[2]*v[1])
    newList.append(u[0]*v[2]-u[2]*v[0])
    newList.append(u[0]*v[1]-u[1]*v[0])
    return newList

def are_colinear(u,v):
    """
    >>> are_colinear([1, 2, 3], [4, 8, 12])
    True
    """

    if(len(u) != len(v)):
        return False
    #loop to see if there is a division by zero. If there is the program returns false
    for i in range(0, len(u)-1):
        if(u[i] == 0 and v[i] != 0) or (u[i] != 0 and v[i] == 0):
            return False
    #counts the ratio of the elements from two vectors
    ratio = u[0]/v[0]
    #if the ratios are equal the program return true
    for i in range(0, len(u)-1):
        if(u[i] == 0 and v[i] == 0):
            continue
        if u[i]/v[i] != ratio:
            return False
    return True
def are_perpendicular(u,v):
    """
    >>> are_perpendicular([3,4], [-8,6])
    True
    """

    #the two vectors are perpendicular only if the dot product of the them is zero
    if dot_product(u,v) == 0:
        return True
    else:
        return False

if __name__ == "__main__":
    import doctest
    doctest.testmod()

