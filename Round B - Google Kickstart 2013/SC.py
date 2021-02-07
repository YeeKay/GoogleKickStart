import numpy as np
import sys
def check_column_row(matrix,dimension):
    for b in range(0,dimension):
        if sorted(matrix[b])!=list(range(1,dimension+1)) or sorted(matrix[:,b])!=list(range(1,dimension+1)):
            return False

def check_box(rowstart,rowend,columnstart,columnend,size,dimension,matrix):
    while rowend<=dimension:
        while columnend<=dimension:
            result=matrix[rowstart:rowend,columnstart:columnend].flatten()
            if(sorted(result)!=list(range(1,dimension+1))):
                return False
            columnstart=columnstart+size
            columnend=columnend+size
        rowstart=rowstart+size
        rowend=rowend+size
        columnstart=0
        columnend=size

num_of_test_case=int(input())
for x in range(1,num_of_test_case+1):
    matrix=[]
    size=int(input())
    dimension = size * size
    for a in range(1,dimension+1):
        row = list(map(int,input().split()))
        matrix.append(row)  
    matrix=np.array(matrix)
    #check column
    if (check_column_row(matrix,dimension)==False):
        print("Case #{}: No".format(x))
        continue
    rowstart=0
    rowend=size
    columnstart=0
    columnend=size
    if(check_box(rowstart,rowend,columnstart,columnend,size,dimension,matrix)==False):
        print("Case #{}: No".format(x))
    else:
        print("Case #{}: Yes".format(x))