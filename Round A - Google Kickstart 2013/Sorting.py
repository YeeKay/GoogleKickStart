import sys
T=int (input())
for x in range (1, T + 1):
    Number_Of_Book = int(input())
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
    odd_iterator=iter(odd.sort())
    even_iterator=iter(even.sort(reverse=True))
    for a in inp:
        if ( a % 2 ) == 0:
            output.append(str(next(even_iterator)))
            continue
        else:
            output.append(str(next(odd_iterator)))
            continue
    output=' '.join(output)
    print(f"Case #{x}: {output}")
