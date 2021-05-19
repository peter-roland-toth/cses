#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

struct point {
    int x;
    int y;

    bool operator==(const point& a) const {
        return (x == a.x && y == a.y);
    }

    bool operator!=(const point& a) const {
        return !(x == a.x && y == a.y);
    }
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
  vector<vector<point>> parent(n, vector<point>(m));

  point start, end;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      if (x == '.' || x == 'A' || x == 'B') {
        v[i][j] = 0;
        visited[i][j] = false;
        if (x == 'A') {
          start = {i, j};
          visited[i][j] = true;
        } else if (x == 'B') {
          end = {i, j};
        }
      }
    }
  }

  q.push(start);

  while (q.size() > 0) {
    point visiting = q.front();

    if (visiting == end) {
      cout << "YES" << endl;

      point current = end;
      vector<char> path;
      while (current != start) {
        point next = parent[current.x][current.y];
        point diff = {current.x - next.x, current.y - next.y};
        
        if (diff == point{1, 0}) {
          path.push_back('D');
        } else if (diff == point{-1, 0}) {
          path.push_back('U');
        } else if (diff == point{0, 1}) {
          path.push_back('R');
        } else if (diff == point{0, -1}) {
          path.push_back('L');
        }
        current = next;
      }

      cout << path.size() << endl;
      for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
      }
      cout << endl;

      return 0;

    }

    q.pop();
    for (int k = 0; k < 4; k++) {
      int n_x = visiting.x + neighbor_x[k];
      int n_y = visiting.y + neighbor_y[k];
      if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m && visited[n_x][n_y] == false) {
        visited[n_x][n_y] = true;
        parent[n_x][n_y] = visiting;
        point to_visit = {n_x, n_y};
        q.push(to_visit);
      }
    }
  }

  cout << "NO" << endl;
}
