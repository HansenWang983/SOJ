//
//  main.cpp
//  shortest_path_in_unweighted graph
//
//  Created by 16340232 on 2017/11/29.
//  Copyright © 2017年 hansen. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace  std;
int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    int dis[1000];
    for(int i=0;i<n;i++)
        dis[i]=-1;
    bool array[1000][1000];
    bool visited[1000];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            array[i][j]=false;
        }
    }
    for(int i=0;i<n;i++)
        visited[i]=false;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        array[a-1][b-1]=true;
        array[b-1][a-1]=true;
    }
    queue<int> q;
    int count=0,source=0;
    q.push(source);
    visited[source]=true;
    dis[source]=0;
    cout<<endl;
    while(!q.empty()){
        count++;
        int j = q.size();
        while (j--)
        {
            source = q.front();
            q.pop();
            for (int i = 0; i < n ; i++)
            {
                if (array[source][i]&&(!visited[i]))
                {
                    dis[i] = count;
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    return 0;
}
