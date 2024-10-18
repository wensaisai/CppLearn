#pragma once
#include <iostream>
using namespace std;

// char* message is a pointer to a string *message = 
void Log(const char* message){
    cout << "message is " << *message << endl;
    std::cout << message << std::endl;
}

void twoDArray(){
    int n;
    cin >> n;
    int arr[n+3][n+3];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

