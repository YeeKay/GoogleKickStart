/* Copyright © 2020 Yee Kay Tan - All Rights Reserved
 */
/** The following code only passes Test Set 1. However, it returned wrong answer
for Test Set 2 */ 

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility> 
#include <math.h>
#include <map>
using namespace std;
//map<index,element> tree
static map<int,pair<int,int>> tree;

//Find nth element of the array 
pair<int,int> helper(map<int,pair<int,int>> tree, int pos)
{
    auto it=tree.find(pos);
    // empty node at the tree index
    if (it==tree.end())
    {
        pair<int,int> ancestor=helper(tree,pos/2);
        pair<int,int> res;
        //left child
        if(pos%2==0)
        {
            res.first=ancestor.first;
            res.second=ancestor.first+ancestor.second;
            tree.insert({pos,res});
        }
        else
        {
            res.first=ancestor.first+ancestor.second;
            res.second=ancestor.second;
            tree.insert({pos,res});
        }
        return res;        
    }
    else
    {
        pair<int,int>res;
        res.first=it->second.first;
        res.second=it->second.second;
        return res;
    }   
}
    
int main()
{
    int num,id,pos,p,q;
    pair<int,int> root;
    //initialize root 
    root.first=1;
    root.second=1;
    //tree nodes
    tree.insert({1,root});
    int a ,b;
    cin >> num;
    for (int i=1;i<=num;i++)
    {
        cin >> id; 
        //Problem ID 1: Find nth element of array 
        if (id ==1)
        {
            pair<int,int>ans;
            cin >> pos;
            ans=helper(tree,pos);
            p=ans.first;
            q=ans.second;
            cout <<  "Case #" <<i <<": " <<p << " " << q << "\n";
        }
        // Problem ID 2: Find position of p/q in array 
        else
        {
            vector<int32_t> parents;
            cin >> a >> b; 
            while (a != 1 || b !=1 )
            {
                //1 = 'L' 2 = 'R'
                //left child 
                if (a < b)
                {
                    parents.emplace_back(1);
                    b = b - a ;
                }
                //right child 
                else  
                {
                    parents.emplace_back(2);
                    a = a - b ; 
                }
            }
            int result=0;
            int counter=parents.size();
            reverse(parents.begin(),parents.end());
            for (int i=0;i<counter;i++)
            {
                result += pow(2,i);
            }
            for(auto item: parents)
            {
                counter -=1;
                if (item==2)
                {
                    result+=pow(2,counter);
                }
            }
            cout <<  "Case #" <<i << ": "<< result + 1 << "\n";
        }
    }
}
