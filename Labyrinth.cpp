#include <iostream>
#include<map>
#include<vector>
#include<stack>
#include<list>
#include<algorithm>
using namespace std;

unsigned int n, m, s;
int a, b,last=0,element;
bool found = false;
int PathNum = 0;
int FoundPathes = 0;
vector<vector<int>> pathes;
bool flag = true,flag2=false,flag3=false;



class Graph {
public:
    map<int, bool> visited;
    map<long, list<long> > adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    //keys.push_back(v);
}
void Graph::DFS(int v)
{
    if (flag3)
        return;
    if (flag == true) {
        if (visited[v])
        {
            found = true;
            if (last == 0)
            {
                last = v;
                return;
            }

        }
        else { visited[v] = true; }
    }
    flag = false;
    // Recur for all the vertices adjacent
    // to this vertex
    
    list<long>::iterator itr;
    for (itr = adj[v].begin(); itr != adj[v].end(); ++itr)
    {
        
        if ((!visited[*itr]) )
        {
            if (*itr != s)
            {
                
                pathes[PathNum].push_back(*itr);
                visited[*itr] = true;

                DFS(*itr);
                if (flag3)
                    return;
            }
          
        }
        else {
            if (*itr != s)
            {
                vector<int>::iterator it;
                it = find(pathes[PathNum].begin(), pathes[PathNum].end(), *itr);
                if (it == pathes[PathNum].end())
                {
                    pathes[PathNum].push_back(*itr);
                    found = true;
                    if (last == 0)
                    {
                        last = *itr;
                        flag3 = true;
                        return;
                    }


                }
            }
             }
        }
   

}
void GeneratePath(Graph g) {
    stack<int> passs;
    passs.push(last);
    while (true) {
  
        vector<int>::iterator it;
        list<long>::iterator it2;
        it = find(pathes[FoundPathes].begin(), pathes[FoundPathes].end(), last);
        if (it != pathes[FoundPathes].end())
        {
            int pos = it - pathes[FoundPathes].begin();
            element = last;
            for (int i = pos; i > 0; --i)
            {

                it2 = find(g.adj[pathes[FoundPathes][i - 1]].begin(), g.adj[pathes[FoundPathes][i - 1]].end(), element);
                if (it2 != g.adj[pathes[FoundPathes][i - 1]].end())
                {

                    passs.push(pathes[FoundPathes][i - 1]);
                    element = pathes[FoundPathes][i - 1];


                }

            }

            cout << passs.size() << endl;;
            while (!passs.empty())
            {
                int x = passs.top();

                // Pop the top element
                passs.pop();


                if (passs.size())
                    cout << x << ' ';
                else
                    cout << x;
            }
            cout << endl;


            
            break;
        }
        else
        {

            FoundPathes++;
            continue;
        }
    }
 




}
int main() {
  
    Graph g;

    
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    int sz = size(g.adj[s]);
    list<long>::iterator itr2;
    itr2 = g.adj[s].begin();

    if (sz > 1) {
        while (!found && (sz > 0)) {
            pathes.push_back(vector<int>());
            pathes[PathNum].push_back(s);
            pathes[PathNum].push_back(*itr2);
            g.DFS(*itr2);
            flag = true;
            itr2++;
            sz--;
            PathNum++;
        }

    }
    else {
        cout << "Impossible"<<endl;
        cin.get();
        system("pause");
        return 0;
    }
    if (!found) {
        cout << "Impossible"<<endl;
    }
    else {
        cout << "Possible" << endl;
        FoundPathes = 0;
        GeneratePath(g);
        FoundPathes++;

        GeneratePath(g);

    }
            
        cin.get();
        system("pause");
	return 0;
}
// usin depth first search and comparing for many passes to find 2 passes that reach same point (not start)
// to generate the path i made backward search in the path with the map to get keys of values in the vector
// then generate the path from back to start 
//problem link : https://codeforces.com/problemset/problem/1666/L
//difficulty level : 1800