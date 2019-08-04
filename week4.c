#include <stdio.h>
#define INF 999999

int isVisited[10];
int cost[10];
int path[10];
int parent[10];

int graph[5][5] = {
    0, 1, 2, INF, 8,
    INF, 0, INF, 1, 5,
    INF, INF, 0, 1, INF,
    INF, INF, INF, 0, 3,
    INF, INF, INF, INF, 0
    };

int isEdge(s, d){
    return graph[s][d] != INF;
}

int extractMin(){
    int min_cost = INF, min, i;
    for (i = 0; i < 5; i++){
        if (!isVisited[i] && cost[i] < min_cost){
            min = i;
            min_cost = cost[i];
        }
    }

    return min;
}

void reduce(extractedNode, node)
int extractedNode, node;
{
    if (isEdge(extractedNode, node) && cost[node] > cost[extractedNode] + graph[extractedNode][node]) {
        cost[node] = cost[extractedNode] + graph[extractedNode][node];
        parent[node] = extractedNode;
    }
}

void dijkstra(source, destination) int source, destination;
{
    int no_nodes = 5;
    int i, j, n, extractedNode, node, no_path_nodes = 0;

    source--;
    destination--;

    for (i = 0; i < no_nodes; i++)
    {
        cost[i] = INF;
    }

    parent[source] = -1;
    cost[source] = 0;

    for (i = 0; i < no_nodes; i++)
    {
        extractedNode = extractMin();
        isVisited[extractedNode] = 1;

        if (extractedNode == destination)
            break;

        for (node = 0; node < no_nodes; node++)
        {
            reduce(extractedNode, node);
        }
    }

    if (extractedNode != destination)
        printf("NO PATH\n");
    else
    {
        j = destination;
        i = 0;
        while (j != -1)
        {
            path[i++] = j + 1;
            j = parent[j];
            no_path_nodes++;
        }

        for (i = no_path_nodes - 1; i > 0; i--)
        {
            printf("%d-->", path[i]);
        }
        printf("%d\ncost: %d\n", path[0], cost[destination]);
    }
}

int main(int argc, char const *argv[])
{

    int i, j, source, destination;

    scanf("%d %d", &source, &destination);

    dijkstra(source, destination);

    return 0;
}
/*
output
1 5
1-->2-->4-->5
cost: 5
*/
