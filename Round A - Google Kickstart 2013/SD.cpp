#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <math.h>
#include <limits>
#include <set>
#include <array>
using namespace std;

//which neighbor to visit first
int Min_Dist(vector<vector<int>>* graph, unordered_map<int,int> visited, int src,int des,int num_of_room)
{
    int min=2147483647;
    int min_index=0;
    for(int v=1;v<=num_of_room;v++)
    {
        int weight=graph->at(src).at(v);
        if(weight<min && visited.find(v)==visited.end()&&v !=src)
        {
            min_index=v;
            min=weight;
            visited[v]=1;
        }
    }
    return min_index;
    //iterate all neighboring nodes in src row                
}

int djikstra(int num_of_room,vector<vector<int>> *graph,int src,int des)
{
    unordered_map<int,int> visited;
    for(int v=1;v<=num_of_room;v++)
    {
        // find order of nodes to be visited
        int ans=Min_Dist(graph,visited,src,des,num_of_room);
        if (ans !=0)
        {
        int ori=graph->at(src).at(ans);
        visited[ans]=1;
        //djikstra where you iterate all neighbors and compare with row of table
        for(int a=1;a<=num_of_room;a++)
        {
            int weight = graph->at(ans).at(a);
            if(weight>0&&weight!=2147483647)
            {   
                int result=graph->at(src).at(a);
            //     // cout <<"graph["<<src<<"]["<<ans<<"]="<<graph[src][ans]<<"\n";
            //     // cout <<"graph["<<ans<<"]["<<a<<"]="<<graph[ans][a]<<"\n";
                 int dist=ori+weight;
                 if(dist < result)
                 {   
                   graph->at(src).at(a)=dist;
                 } 
            }
        }
        }  
    }
   return graph->at(src).at(des);
}

int mapping(unordered_map<int,int>m,int query)
{
    return m.find(query)-> second;
}

int main()
{
    int num_of_test_case,num_of_room,num_of_turbolift;
    int src,des,weight;
    int num_of_request;
    string room_name;
    cin >> num_of_test_case;
    for (int i=1;i<=num_of_test_case;i++)
    {
        cout <<"Case #"<<i<<":"<<"\n";
        unordered_map<string,int>room_names_hashmap;
        unordered_map<int,int> num_mapping;
        cin >> num_of_room;
        //come up with num_mapping list which combines rooms of same color
        for(int a=1;a<=num_of_room;a++)
        {
            cin >> room_name;
            std::unordered_map<std::string,int>::const_iterator got=room_names_hashmap.find(room_name);
            //first ever room
            if(got==room_names_hashmap.end())
            {
                room_names_hashmap[room_name]=a;
            }
            else
            {
                num_mapping[a]=got->second;
            }   
        }
        vector<vector<int>> graph(num_of_room+1,vector<int>(num_of_room+1,numeric_limits<int>::max()));
        for(int i=1;i<=num_of_room;i++)
        {
            graph[i][i]=0;
        }
        cin>>num_of_turbolift;
        for(int a=0;a<num_of_turbolift;a++)
        {
          cin >> src >> des >> weight;
          if(num_mapping[src]!=NULL)
          {
          src=mapping(num_mapping,src);    
          }
          if(num_mapping[des]!=NULL)
          {
          des=mapping(num_mapping,des);    
          }
          //construct the graph
           if (src!=des&&(isinf(graph[src][des])||weight<graph[src][des]))
          {
              graph[src][des]=weight;
          }
        }
        cin >> num_of_request;
        unordered_map<int,int> tried;
        for (int i=1;i<=num_of_request;i++)
        {
            cin >> src >> des;
            if(num_mapping[src]!=NULL)
            {
            src=mapping(num_mapping,src);    
            }
            if(num_mapping[des]!=NULL)
            {
            des=mapping(num_mapping,des);    
            }
            int ans=djikstra(num_of_room,&graph,src,des);
            if(ans==2147483647)
            {
                cout << -1 <<"\n";
            }
            else
            {
              cout <<ans<<"\n";   
            }
        }
    }
}