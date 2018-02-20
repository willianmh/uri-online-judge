#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long int n1, n2;

    vector<int> pot_dois;

    for(int i = 0; i <= 32; i++)
        pot_dois.push_back((int)pow(2, i));


    while (cin.eof())
    {
        scanf(" %ld %ld", &n1, &n2);
    printf(" %ld %ld\n", n1, n2);

        vector<int> fatores_n1;
        vector<int> fatores_n2;
        vector<int> v;

        long int r = 0;

        int m, n;

        for (m = 0; m <= 32 && max(n1, (long int)pot_dois[m]) <= n1; m++);
        for (n = 0; n <= 32 && max(n2, (long int)pot_dois[n]) <= n2; n++);


        for(int i = m; i >= 0 && n1 > 0; i--) {
            if(n1 >= pot_dois[i]){
                n1 -= pot_dois[i];
                fatores_n1.push_back(pot_dois[i]);
            }
        }

        for(int i = n; i >= 0 && n2 > 0; i--) {
            if(n2 >= pot_dois[i]){
                n2 -= pot_dois[i];
                fatores_n2.push_back(pot_dois[i]);
            }
        }

        for (auto f2 = fatores_n2.begin(); f2 != fatores_n2.end(); f2++) {
            bool apagou = false;
            for (auto f1 = fatores_n1.begin(); f1 != fatores_n1.end() && !apagou; ) {
                if (*f1 == *f2) {
                    fatores_n1.erase(f1);
                    apagou = true;
                } else {
                    f1++;
                }
            }
            if(!apagou)
                fatores_n1.push_back(*f2);
        }

        for (auto i : fatores_n1)
            r += i;

        cout << r << endl;
    }


    return 0;
}