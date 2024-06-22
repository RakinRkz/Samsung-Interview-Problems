// O(N^3) Solution
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int i, j, k, n, m, maxMove;
    cin >> n >> m >> maxMove;
    int matrix[n][m];
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            cin >> matrix[i][j];
        }
    }
    int alreadyEqual = 0;
    int list[n];
    memset(list, 0, n*sizeof(int));
    //counting rows that are already full of 1's
    for(i=0;i<n;i++) {
        int flag = 1;
        if(matrix[i][0] == 0) {
            flag = 0;
        } else {
            for(j=0;j<m;j++) {
                if(matrix[i][j] != matrix[i][0]) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1) {
            alreadyEqual++;
        }
    }
    //clustering | counting for each row, how many other rows are same as it.
    for(i=0;i<n;i++) {
        if(list[i] == -1)
            continue;
        for(j=i+1;j<n;j++) {
            int flag = 1;
            for(k=0;k<m;k++) {
                if(matrix[i][k] != matrix[j][k]) {
                    flag = 0;
                }
                if(flag == 0)
                    break;
            }
            if(flag == 1) {
                // cout << "Row " << i << " and " << j << " are similiar" << endl;
                list[i]++;
                list[j] = -1;
            }
        }
    }

    for(i=0;i<n;i++) {
        // cout << list[i].size() << endl;
        int zero = 0, ones = 0;
        for(j=0;j<m;j++) {
            if(matrix[i][j] == 1)
                ones++;
        }
        zero = m - ones;
        // for this row, we counted how many 0's and 1's it has.
        // we check if cluster size of this row is greater than the number of rows full of 1's
        // and allowed moves left after flipping the 0's of this row cluster is even(because 
        // odd number of actions left will cause chaos)
        if(list[i]+1 > alreadyEqual && (maxMove-zero)%2==0)
            alreadyEqual = list[i]+1;
    }
    cout << alreadyEqual << endl;

    return 0;
}
