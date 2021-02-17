#include<iostream>
#include<vector>
#include<stack>
#include <queue>
using namespace std;

int n, k, m;
vector<vector<int>> graph;
vector<bool> used;

bool isObstacle(int v) {
    return v < m;
}

bool safePathWrapped(int v, int u) {
    if (v == u) {
        return true;
    }

    if (used[v]) {
        return false;
    }

    used[v] = true;

    for (int child : graph[v]) {
        if (isObstacle(v)) {
            if (!isObstacle(child) && safePathWrapped(child, u)) {
                return true;
            }
        }
        else if (safePathWrapped(child, u)) {
            return true;
        }
    }

    return false;
}

bool safepath(int v, int u) {
    used.clear();
    used.resize(n);
    return safePathWrapped(v, u);
}


vector<int> survivor(int v, int u) {
    used.clear();
    used.resize(n);

    queue<int> q;

    q.push(v);

    vector<int> parent;
    parent.resize(n);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == u) {
            break;
        }

        used[current] = true;

        for (auto child : graph[current]) {
            if (!used[child]) {
                parent[child] = current;
                q.push(child);
            }
        }
    }

    int counter = 0;
    stack<int> s;

    int current = u;

    while (current != v) {
        if (isObstacle(current)) {
            counter++;
        }
        s.push(current);

        current = parent[current];
    }

    if (isObstacle(v)) {
        counter++;
    }
    s.push(v);

    if (counter > m / 2) {
        return vector<int>();
    }

    vector<int> path;

    while (!s.empty()) {
        path.push_back(s.top());
        s.pop();
    }

    return path;
}

int main() {
    cin >> n >> k >> m;

    graph.resize(n);

    int v, u;
    for (int i = 0; i < k; i++) {
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    cout << safepath(3, 0) << endl;
    vector<int> result = survivor(3, 0);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    return 0;
}