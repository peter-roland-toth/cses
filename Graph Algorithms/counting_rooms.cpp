#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

struct point {
    int x;
    int y;
};

int main ()
{
  long n, m;
  cin >> n >> m;

  queue<point> q;
  vector<int> neighbor_x = {0, 0, -1, 1};
  vector<int> neighbor_y = {1, -1, 0, 0};

  vector<vector<int>> v(n, vector<int>(m, 1));
  vector<vector<bool>> visited(n, vector<bool>(m, true));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      if (x == '.') {
        v[i][j] = 0;
        visited[i][j] = false;
      }
    }
  }

  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 0 && visited[i][j] == false) {
        point p = {i, j};
        q.push(p);
        visited[i][j] = true;

        while (q.size() > 0) {
          point visiting = q.front();
          q.pop();
          for (int k = 0; k < 4; k++) {
            int n_x = visiting.x + neighbor_x[k];
            int n_y = visiting.y + neighbor_y[k];
            if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m && visited[n_x][n_y] == false) {
              visited[n_x][n_y] = true;
              point to_visit = {n_x, n_y};
              q.push(to_visit);
            }
          }
        }

        result += 1;
      }
    }
  }

  cout << result << endl;
}
