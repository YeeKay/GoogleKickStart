#include <iostream>
#include <vector>
using namespace std;

//(row,column)
/*
R1,C1 R1,C2
R2,C1 R2,C2 
*/
// graph[row][column]
// currentPosition = (row,column)
//#(1,1)
static pair<int,int> currentPosition;
static char currentOrientation;

bool checkLeft(vector<vector<int>>graph,int size, pair<int,int> currentPosition,char orientation)
{
    switch (orientation)
    {
        case 'S':
            if(size<currentPosition.second + 1)
            {   
            return false;
            }
            else
            {
                if(graph[currentPosition.first-1][currentPosition.second]==0)
                {
                return false;
                }
                else
                {
                    return true;
                }
                
            }
        break;  

        case 'E':
            if(currentPosition.first<=1)
            {
                return false;
            } 
            else
            {
                if(graph[currentPosition.first-2][currentPosition.second-1]==0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
                
            }
        break;

        case 'N':
            if (currentPosition.second<=1)
            {
                return false;
            }
            else
            {
                if(graph[currentPosition.first-1][currentPosition.second-2]==0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
                
            }
        break;

        case 'W':
            if(size<currentPosition.first+1)
            {
                return false;
            }
            else
            {
                if(graph[currentPosition.first][currentPosition.second-1]==0)
                {
                    return false;
                }
                else
                {
                    return true;
                }          
            }
            break;
    }  
}

bool checkStraight(vector<vector<int>>graph,int size, pair<int,int> currentPosition,char orientation)
{
    switch (orientation)
    {
        case 'E':
            if(size<currentPosition.second + 1)
            {   
            return false;
            }
            else
            {
                if(graph[currentPosition.first-1][currentPosition.second]==0)
                {
                return false;
                }
                else
                {
                return true;
                }
                
            }
        break;  

        case 'N':
            if(currentPosition.first<=1)
            {
                return false;
            } 
            else
            {
                if(graph[currentPosition.first-2][currentPosition.second-1]==0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
                
            }
        break;

        case 'W':
            if (currentPosition.second<=1)
            {
                return false;
            }
            else
            {
                if(graph[currentPosition.first-1][currentPosition.second-2]==0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
                
            }
        break;

        case 'S':
            if(size<currentPosition.first+1)
            {
                return false;
            }
            else
            {
                if(graph[currentPosition.first][currentPosition.second-1]==0)
                {
                    return false;
                }
                else
                {
                    return true;
                }          
            }
            break;
    }  
}

char moveStraight(char orientation)
{
    switch (orientation)
    {
        case 'S':
            currentPosition.first=currentPosition.first+1;
            currentOrientation='S';  
            return 'S';
        
        case 'E':
            currentPosition.second=currentPosition.second+1;
            currentOrientation='E';
            return 'E';
        
        case 'N':
            currentPosition.first=currentPosition.first-1;    
            currentOrientation='N';
            return 'N';

        case 'W':
            currentPosition.second=currentPosition.second-1;
            currentOrientation='W';
            return 'W';       
    }
}



char turnLeft(char orientation)
{
    switch (orientation)
    {
        case 'S':
            currentPosition.second=currentPosition.second+1;
            currentOrientation='E';  
            return 'E';
        
        case 'E':
            currentPosition.first=currentPosition.first-1;
            currentOrientation='N';
            return 'N';
        
        case 'N':
            currentPosition.second=currentPosition.second-1;    
            currentOrientation='W';
            return 'W';

        case 'W':
            currentPosition.first=currentPosition.first+1;
            currentOrientation='S';
            return 'S';       
    }
}

char turnRight(char orientation)
{
    switch (orientation)
    {
        case 'S':
            currentOrientation='W';  
            return 'W';
        
        case 'E':
            currentOrientation='S';
            return 'S';
        
        case 'N':    
            currentOrientation='E';
            return 'E';

        case 'W':
            currentOrientation='N';
            return 'N';       
    }
}

int main()
{
    int n;
    cin>>n;
    char tile;
    for(int i=1;i<=n;i++)
    {
        int srow,scol,erow,ecol;
        currentOrientation='S';
        int steps=0;
        string path;
        int size;
        cin >> size;
        vector<vector<int>> graph(size,vector<int>(size,999));
        for(int row=0;row<size;row++)
        {
            for(int column=0;column<size;column++)
            {
                cin >> tile;
                if (tile=='.')
                {
                   graph[row][column]=1; 
                }
                else
                {
                    graph[row][column]=0;
                }
            }
        }
        cin >>srow >> scol >> erow >> ecol;
        currentPosition.first=srow;
        currentPosition.second=scol;
        int loop_counter=0;
        //can move left 
        while(currentPosition.first !=erow || currentPosition.second !=ecol)
        {
            if(steps>=10000)
            {
            cout << "Case #" <<i <<": Edison ran out of energy." << "\n"; 
            break;
            }
            if(checkLeft(graph,size,currentPosition,currentOrientation)==1)
            { 
            char p=turnLeft(currentOrientation);
            steps+=1;
            path +=p;
            loop_counter=0;
            continue;
            }
            if(checkStraight(graph,size,currentPosition,currentOrientation)==1)
            {
                char p=moveStraight(currentOrientation);
                steps+=1;
                path +=p;
                loop_counter=0;
                continue;
            }
            loop_counter+=1;
            if(loop_counter>=4)
            {
                cout << "Case #" <<i<<": Edison ran out of energy." << "\n"; 
                break;
            }
            currentOrientation=turnRight(currentOrientation);
        }
        if(steps>0 && steps<10000)
        {
            cout <<"Case #"<<i<<":"<< steps<<"\n";
            cout <<path<<"\n";
        }
    }
}