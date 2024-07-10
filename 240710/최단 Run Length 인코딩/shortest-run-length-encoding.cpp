#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;


string run_length_encoding(string input){
    int arr[input.size()];
    vector<char> temp;
    for(int i = 0; i < input.size(); i++){
        arr[i] = 1;
    }
    
    if(input.size() == 1){
        temp.push_back(input[0]);
        temp.push_back('1');
        string str(temp.begin(), temp.end());
        return str;
    }
    for(int i = 1; i < input.size(); i++){
        if(input[i - 1] == input[i]){
            arr[i] = arr[i - 1] + 1;
        }
    }

    vector <char> result;
    result.push_back(input[0]);
    for(int i = 1; i < input.size(); i++){
        if(input[i - 1] != input[i]){
            int before_temp = arr[i - 1];
            char after_temp = before_temp + '0';
            result.push_back(after_temp);
            //cout << arr[i - 1] << endl;
            result.push_back(input[i]);
        }
    }
    int before = arr[input.size() - 1];
    char after = before + '0';
    if(before == 10){
        result.push_back('1');
        result.push_back('0');
        string str(result.begin(), result.end());
        return str;
    }
    result.push_back(after);
    string str(result.begin(), result.end());
    return str;
}

int main() {
    string input;
    cin >> input;
    
    // string hi = run_length_encoding(input);
    
    // for(int i = 0; i < hi.size(); i++){
    //     cout << hi[i];
    // }
    int result = 1000000;
    for(int i = 0; i < input.size() - 1; i++){
        char end = input[input.size() - 1];
        for(int i = input.size() - 2; i >= 0; i--){
            input[i + 1] = input[i];
        }
        input[0] = end;
        int result_size = run_length_encoding(input).size();
        if(result_size < result){
            result = result_size;
        }
    }
    cout << result;
    return 0;
}