#include<iostream>
using namespace std;
#define NMAX 100
#define MMAX 1000
struct Node
{
    int info;
    Node* pNext;
    Node()
    { 
        pNext=NULL; 
    }
};
Node* List[NMAX];
int u,v,m,n;
    
//Duyệt đỉnh kề của u 
void indinhke(int u)
{
    Node *p = List[u];
    while (p!=NULL)
    {
        cout << p->info << endl;
        p=p->pNext;
    }
}
int main(){
    
    // Nhập số đỉnh và số cạnh
    cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        cin >> u >> v;
        Node *p = new Node();
        p->info = v;
    
        if (List[u]==NULL)
            List[u] = p;
        else
        {
            p->pNext = List[u];
            List[u] = p;
        }
    } 
}
