#include <bits/stdc++.h>
using namespace std;

#define  endl          '\n'
#define  pi            pair<int, int>
#define  vc            vector<char>
#define  vvc           vector<vc>
#define  mi            map<int, int>
#define  vmi           vector<mi>
#define  f(i, in, n)   for (int i = in; i < n; i++)
#define  fast          ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve_suduko(int r, int c, vvc &a, map<pi, mi> &mp, vmi &row, vmi &col){
    if (r == 9){
        f(i, 0, 9){
            if (i % 3 == 0) cout << " -----------------------" << endl;
            f(j, 0, 9){
                if (j % 3 == 0) cout << "| ";
                cout << a[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << " -----------------------" << endl << endl;
        return;
    }

    if (c == 9){
        solve_suduko(r + 1, 0, a, mp, row, col);
        return;
    }

    if (a[r][c] != '.'){
        solve_suduko(r, c + 1, a, mp, row, col);
        return;
    }

    f(i, 1, 10){
        int rw = r / 3, cw = c / 3;
        if (!mp[{rw, cw}][i] && !row[r][i] && !col[c][i]){
            mp[{rw, cw}][i] == 1;row[r][i] = 1;col[c][i] = 1;
            a[r][c] = i + '0';
            solve_suduko(r, c + 1, a, mp, row, col);
            mp[{rw, cw}][i] == 0;row[r][i] = 0;col[c][i] = 0;
            a[r][c] = '.';
        }
    }
    return;
}

int main(){
    fast;

    vvc a(9, vc(9));
    map<pi, mi> mp;
    vmi row(9);
    vmi col(9);

    cout << "Enter 9X9 unsolved suduko" << endl;
    cout << "Write blank space as dot(.)" << endl;

    f(i, 0, 9){
        f(j, 0, 9){
            cin >> a[i][j];

            if (a[i][j] != '.'){
                int el = a[i][j] - '0';
                mp[{i / 3, j / 3}][el] = 1;
                row[i][el] = 1;
                col[j][el] = 1;
            }
        }
    }
    solve_suduko(0, 0, a, mp, row, col);

    return 0;
}
