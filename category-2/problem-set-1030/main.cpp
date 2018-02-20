#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {

    int NC;

    scanf(" %d", &NC);

    for (int a = 1; a <= NC; a++) {
      int n, k;
      scanf(" %d %d", &n, &k);

      vector<int> v;

      for (int i = 0; i < n; i++)
        v.push_back(i + 1);

      int i = k - 1;
      while (v.size() > 1) {
        while (i >= v.size())
          i = i - v.size();

        v.erase(v.begin() + i);

        i = i + k - 1;
      }
      printf("Case %d: %d\n", a, v[0]);
    }


  return 0;
}
