//Nguyen Trung Thanh - 20215482
void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    visited[1] = true;
    /*****************
    # YOUR CODE HERE #
    *****************/
    bool flag = false;
    cout << 1 << "\n";
    while (!S.empty()){
        int v = S.top();
        for (int i : adj[v]){
            if (!visited[i]){
                S.push(i);
                visited[i] = true;
                cout << i << "\n";
                flag = true;
                break;
            }
        }
        if (flag){
            flag = false;
            continue;
        }
        S.pop();
    }
}