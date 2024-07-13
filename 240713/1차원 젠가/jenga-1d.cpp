#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int temp[n];
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int s1, e1, s2, e2;
    cin >> s1 >> e1 >> s2 >> e2;
    s1 = s1 - 1; e1 = e1 - 1; s2 = s2 - 1; e2 = e2 - 1; 
    for(int i = s1; i <= e1; i++){
        arr[i] = 0;
    }
    int start = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            temp[start] = arr[i];
            start++;
        }
    }

    for(int i = 0; i < start; i++){
        arr[i] = temp[i];
    }

    
    for(int i = s2; i <= e2; i++){
        arr[i] = 0;
    }

    int end = 0;
    for(int i = 0; i < start; i++){
        if(arr[i] != 0){
            temp[end] = arr[i];
            end++;
        }
    }
    cout << end << endl;
    for(int i = 0; i < end; i++){
        cout << temp[i] << endl;
    }

    return 0;
}