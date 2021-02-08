/* Copyright © 2020 Yee Kay Tan - All Rights Reserved
 */

import sys
T=int (input())
for x in range (1, T + 1):
    Number_Of_Book = int(input())
    #map input into a list
    inp = list(map(int,input().split()))
    odd=[]
    even=[]
    output=[]
    for i in inp:
        if (i  % 2) == 0:
            even.append(i) 
            continue
        else :
            odd.append(i)
            continue
    #sort odd numbers in ascending order while
    #even numbers in descending order
    odd_iterator=iter(odd.sort())
    even_iterator=iter(even.sort(reverse=True))
    #match odd/even numbers from sorted list based on original input 
    for a in inp:
        if ( a % 2 ) == 0:
            output.append(str(next(even_iterator)))
            continue
        else:
            output.append(str(next(odd_iterator)))
            continue
    #takes all items in an iterable and joins them into one string (output)
    #where ' ' is the separator 
    output=' '.join(output)
    print(f"Case #{x}: {output}")
