   
def find(L, e):
    '''
    returns the index of e in list L
    '''
    mid = len(L)//2
    last = len(L)-1
    first = 0

    while L[mid] == e or L[mid+1] != e:
        if L[mid] >= e:
            last = mid
        else:
            first = mid
        if last - first == 0:
            if L[mid] == e:
                return first # first == last == mid
            else:
                return -1
        mid = (first + last)//2
    return mid + 1

    # while L[mid] != e:
    #     if L[mid] > e:
    #         mid = mid//2

    #     elif L[mid] < e:
    #         first = mid
    #         mid = (first + last)//2
    #     if last-first == 1:
    #         mid = last
    #     if last-first == 0 and L[mid] != e:
    #         return -1
        
        
    # if L[mid] == e:
    #     lowest = mid
    #     while lowest-1 <= 0 and L[lowest-1] == e:
    #         lowest-=1
    #     return lowest

if __name__ == "__main__":
    print(find([1,2,3,4,5,6,7,8,9], 9))
    print(find([1,2,3,4,5,6,7,8,9], 8))
    print(find([1,2,3,4,5,6,7,8,9], 1))
    print(find([1,2,2,2,2,2,2,2,2,2,3,4,5,6,7,8,9], 2))
    print(find([2,2,2,2,2,2,2,2,2,2,2,2], 2))
