//Nguyen Trung Thanh - 20215482
void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    visited[1] = true;
    cout << 1 << "\n";
    /*****************
    # YOUR CODE HERE #
    *****************/
    while (!Q.empty()){
        int v = Q.front();
       
        Q.pop();
        for (int i : adj[v]){
            if (!visited[i]){
                Q.push(i);
                visited[i] = true; 
                cout << i << "\n";
            }
        }
    }
}