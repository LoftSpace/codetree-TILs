#include <iostream>
using namespace std;

int arr[100][100];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    int r, c, m1, m2, m3, m4, dir;
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    int size = m1 + m2 + m3 + m4;
    int square[size];
    int pointer_r = r - 1; int pointer_c = c - 1;
    //m1
    for(int i = 1; i < m1 + 1; i++){
        pointer_r = pointer_r - 1;
        pointer_c = pointer_c + 1;
        square[i] = arr[pointer_r][pointer_c];
        //cout << "pointer_r : " << pointer_r << " pointer_c : " << pointer_c << endl;
        //cout << "square[" << i << "] " << square[i] << endl;
    }
    //m2
    for(int i = m1 + 1; i <= m2 + m1; i++){
        pointer_r = pointer_r - 1;
        pointer_c = pointer_c - 1;
        square[i] = arr[pointer_r][pointer_c];
        //cout << "pointer_r : " << pointer_r << " pointer_c : " << pointer_c << endl;
        //cout << "square[" << i << "] " << square[i] << endl;

    }
    //m3
    for(int i = m1 + m2 + 1; i <= m1 + m2 + m3; i++){
        pointer_r = pointer_r + 1;
        pointer_c = pointer_c - 1;
        square[i] = arr[pointer_r][pointer_c];
        //cout << "square[" << i << "] " << square[i] << endl;

    }
    //m4
    for(int i = m1 + m2 + m3 + 1; i <= m1 + m2 + m3 + m4; i++){
        pointer_r = pointer_r + 1;
        pointer_c = pointer_c + 1;
        square[i % size] = arr[pointer_r][pointer_c];
        //cout << "square[" << i << "] " << square[i] << endl;

    }

    if(dir == 1){
        int temp = square[0];
        for(int i = 1; i < size; i++){
            square[i - 1] = square[i];
        }
        square[size - 1] = temp;
    }
    if(dir == 0){
        int temp = square[size - 1];
        for(int i = size - 1; i >= 0; i--){
            square[i + 1] = square[i];
        }
        square[0] = temp;
    }
    
    pointer_r = r -1; pointer_c = c - 1;
    for(int i = 1; i < m1 + 1; i++){
        pointer_r = pointer_r - 1;
        pointer_c = pointer_c + 1;
        arr[pointer_r][pointer_c] = square[i];
        //cout << "pointer_r : " << pointer_r << " pointer_c : " << pointer_c << endl;
        //cout << "square[" << i << "] " << square[i] << endl;
    }
    //m2
    for(int i = m1 + 1; i <= m2 + m1; i++){
        pointer_r = pointer_r - 1;
        pointer_c = pointer_c - 1;
        arr[pointer_r][pointer_c] = square[i];
        //cout << "pointer_r : " << pointer_r << " pointer_c : " << pointer_c << endl;
        //cout << "square[" << i << "] " << square[i] << endl;

    }
    //m3
    for(int i = m1 + m2 + 1; i <= m1 + m2 + m3; i++){
        pointer_r = pointer_r + 1;
        pointer_c = pointer_c - 1;
        arr[pointer_r][pointer_c]= square[i];
        //cout << "square[" << i << "] " << square[i] << endl;

    }
    //m4
    for(int i = m1 + m2 + m3 + 1; i <= m1 + m2 + m3 + m4; i++){
        pointer_r = pointer_r + 1;
        pointer_c = pointer_c + 1;
        arr[pointer_r][pointer_c] = square[i % size];
        //cout << "square[" << i << "] " << square[i] << endl;

    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}