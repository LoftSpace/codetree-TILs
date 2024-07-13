#include <iostream>
using namespace std;

int arr[100][100];
int temp[100][100];

void zeroing(int n, int r, int c){
    int reach = arr[r][c];
    //0 채우기
    arr[r][c] = 0;
    for(int i = 1; i < reach; i++){
        if(r + i < n){
            arr[r + i][c] = 0;
        }
        if(r - i >= 0){
            arr[r - i][c] = 0;
        }
        if(c + i < n){
            arr[r][c + i] = 0;
        }
        if(c - i >= 0){
            arr[r][c - i] = 0;
        }
    }
}

void gravity(int n){
    for(int i = n - 1; i >= 0; i--){
        int end = n - 1;
        for(int j = n - 1; j >= 0; j--){
            if(arr[j][i] != 0){
               // cout << "j is " << j << " j is " << i << endl;
                temp[end][i] = arr[j][i];
                end--;
                
                
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            temp[i][j] = 0;
        }
    }
    int r, c;
    cin >> r >> c;
    r= r-1; c = c -1;
    zeroing(n, r, c);
    gravity(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ;j++){
            cout << temp[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}