



                         ################### PEAK FINDING ###################





# 1D peak finding   COMPLEXITY --> O(theta)(log n)

def peak_1D(l):

    if len(l) == 1:  # if a singleton list then simply returns the element

        return l[0]



    elif not len(l): # if a null list then returns None

        return None



    else:

        mid = len(l) // 2  # takes a mid index in the list

        if l[mid - 1] > l[mid]:   # checks if the preceding is larger then the mid

            return peak_1D(l[: mid])  # if yes then returns a recursion

        elif l[mid + 1] > l[mid]:  # similar for the next element after mid -->if 'if' fails

            return peak_1D(l[mid + 1:])

        else:               # this means the l[mid - 1] < l[mid] > l[mid + 1]

            return l[mid]    # so l[mid] is the peak





# print(peak_1D([1,2,4,7,8,9,6,5,8,7,4,2,3,6]))





# 2D peak finding    COMPLEXITY --> O(theta)(n log n)

def peak_2D(l):



#[1,2,5,4]

#[7,8,9,6]    # e.g

#[4,8,3,1]

#[9,5,4,7]



    if len(l) == 1:

        if len(l[0]) == 1:

            return l[0][0]

                                    # similar in 1D, just a nested if

        else:

            return None



    elif not len(l):

        return None



    else:

        mid = len(l) // 2     # takes an arbitrary mid row

        # print(max(l[mid]))

        global_row_max = max(l[mid])  # finds the global maximum in the 'mid' row

        column_no = l[mid].index(global_row_max)  # finds the column number of the

        # print(column_no)                        # global max in 'mid' row

        if l[mid - 1][column_no] > l[mid][column_no]:   # similar to 1D compares rows

            return peak_2D(l[: mid + 1])                # in a selected column

        elif l[mid + 1][column_no] > l[mid][column_no]:

            return peak_2D(l[mid + 1:])

        else:                                       # if up_element < the_max in mid row > lower_element

            return l[mid][column_no]                # then it is the 2D peak



# print(peak_2D(

#

# [[1,2,5,4],

# [7,2,1,6],

# [4,1,3,1],

# [1,5,4,2]]

#

# ))


