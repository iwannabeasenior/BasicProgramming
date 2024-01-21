// đồ thị không có hướng , có thể có trọng số âm.

// Thuat toan voi do thi khong co chu trinh am

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
vector<ii> a[181220];
int n, m;

int d[181220];
bool inqueue[181220];
int pre[181220];
vector<int>path;

void bellman(int u) {
    //Buoc 1: Khoi tao
    queue<int> qu;
    for (int i = 1; i <= n; i++) d[i] = 99999999;
    d[u] = 0;
    qu.push(u); //push u vào queue
    inqueue[u] = true; //Đánh dấu đỉnh u đã trong queue
    // Buoc 2: Lap
    while (qu.size()) {
        u = qu.front(); //Lấy giá trị đầu của queue
        inqueue[u] = false; //Đánh dấu là đỉnh u đã pop ra khỏi queue (hay không còn trong queue)
        qu.pop(); // pop đỉnh u ra khỏi queue
        for (int i = 0; i < a[u].size(); i++) { // Duyệt các đỉnh kề u
            int v = a[u][i].second;
            int uv = a[u][i].first;
            if (d[v] > d[u] + uv) {
                d[v] = d[u] + uv;
                pre[v] = u;
                if (!inqueue[v]) { // Nếu đỉnh v chưa trong queue
                    qu.push(v); // Cho v vào queue
                    inqueue[v] = true; // Đánh dấu là đỉnh v đã trong queue
                }
            }
        }
    }
}

int main() {
    int u, v; // dinh nguon va dinh dich
    scanf("%d%d%d%d", &n, &m, &u, &v);
    while (m--) {
        int p, q, w;
        scanf("%d%d%d", &p, &q, &w);
        // Do thi vo huong
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    bellman(u);
    printf("%d\n", d[v]);
    for(int i = v; i != u;  i = pre[i]) path.push_back(i); // them dinh vao duong di
    path.push_back(u);
    reverse(path.begin(), path.end());
    printf("Duong di: ");
    for(int i = 0; i < path.size(); i++){
    	if(i == path.size() - 1){
    		printf("%d", v);
    		break;
	}
   	printf("%d -> ",path[i]);
    }
}

