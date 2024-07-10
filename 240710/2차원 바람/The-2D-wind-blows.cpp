#include <iostream>
using namespace std;

int arr[100][100];
int temp[100][100];

void rotate(int r1, int c1, int r2, int c2){
    int temp1 = arr[r1][c2];
    int temp2 = arr[r2][c2];
    int temp3 = arr[r2][c1];
    for(int i = c2 - 1; i >= c1; i--){
        arr[r1][i + 1] = arr[r1][i];
    }
    for(int i = r2 - 1; i >= r1 + 1; i--){
        arr[i + 1][c2] = arr[i][c2];
    }
    arr[r1 + 1][c2] = temp1;
    for(int i = c1 + 1; i < c2 + 1; i++){
        arr[r2][i - 1] = arr[r2][i];
    }
    arr[r2][c2 - 1] = temp2;
    for(int i = r1 + 1; i < r2 + 1; i++){
        arr[i - 1][c1] = arr[i][c1];
    }
    arr[r2 - 1][c1] = temp3;
}

int mean(int n, int m, int r, int c){
    int adj_count = 1;
    bool add_flage[4];
    for(int i = 0; i < 4; i++) add_flage[i] = false;
    if(c - 1 >= 0) {adj_count++; add_flage[0] = true;}
    if(r - 1 >= 0) {adj_count++; add_flage[1] = true;}
    if(c + 1 < m) {adj_count++; add_flage[2] = true;}
    if(r + 1 < n) {adj_count++; add_flage[3] = true;}
    int result = temp[r][c];
    if(add_flage[0]) result += temp[r][c - 1];
    if(add_flage[1]) result += temp[r - 1][c];
    if(add_flage[2]) result += temp[r][c + 1];
    if(add_flage[3]) result += temp[r + 1][c];
    
    //cout << "r is " << r << " c is " << c << " result is "<< result <<endl;
    return result/adj_count;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int r1[q]; int r2[q]; int c1[q]; int c2[q];
    for(int i = 0; i < q; i++){
        cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
        r1[i] = r1[i] - 1; c1[i] = c1[i] - 1; r2[i] = r2[i] - 1; c2[i] = c2[i] - 1;
    }
    for(int k = 0; k < q; k++){
        rotate(r1[k], c1[k], r2[k], c2[k]);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                temp[i][j] = arr[i][j];
            }
        }
        for(int i = r1[k]; i < r2[k] + 1; i++){
            for(int j = c1[k]; j < c2[k] + 1; j++){
                arr[i][j] = mean(n, m, i, j);
            }
        }
    }
    
    

    for(int i = 0; i < n ;i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}