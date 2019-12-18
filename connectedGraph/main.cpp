#include <iostream>
#include "linkQueue.cpp"

using namespace std;

bool bfs_connected(int *&neighbourMat, int num);

int main()
{
    int vertexNum = 0;
    int *neighbourMatrix;
    int edgeNum = 0;

    // get the number of vertices, number of edges and construct neighbour matrix
    cin >> vertexNum;
    neighbourMatrix = new int[vertexNum * vertexNum];
    for (int i = 0; i < vertexNum; ++i)
        for (int j = 0; j < vertexNum; ++j)
        {
            cin >> neighbourMatrix[i * vertexNum + j];
            if (neighbourMatrix[i * vertexNum + j] == 1)
                edgeNum++;
        }
    cout << edgeNum / 2 << endl;

    // bfs to verify if the graph is connected
    bool connected = bfs_connected(neighbourMatrix, vertexNum);

    // output neighbour table
    for (int i = 0; i < vertexNum; ++i)
    {
        cout << i << ' ';
        for (int j = 0; j < vertexNum; ++j)
            if (neighbourMatrix[i * vertexNum + j] == 1)
                cout << j << ' ';
        cout << endl;
    }

    // output connected information
    if (connected) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

bool bfs_connected(int *&neighbourMat, int num)
{
    linkQueue<int> que;

    bool *visited = new bool[num];
    for (int i = 0; i < num; ++i)
        visited[i] = false;

    que.enQueue(0);
    visited[0] = true;
    int currVer;
    while(!que.isEmpty())
    {
        currVer = que.deQueue();
        for (int i = 0; i < num; ++i)
            if (neighbourMat[currVer * num + i] == 1 && !visited[i])
            {
                que.enQueue(i);
                visited[i] = true;
            }
    }

    for (int i = 0; i < num; ++i)
        if (!visited[i])
            return false;
    
    return true;
}