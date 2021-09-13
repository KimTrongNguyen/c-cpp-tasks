#include <iostream>
#include <fstream>

using namespace std;

void readFile() {
    int stop = 0;
    string filePath;
    string line;
    fstream file;
    do {
        cout << "Enter the file path: ";
        cin >> filePath;
        getchar();
        //Read file
        file.open(filePath, ios::in);
        //Read line by line without skipping white space
        cout << "File content: " << endl;
        while(getline(file, line)) {
            cout << line << endl;
        }
        file.close();
        //Ask for stop or continue
        cout << "Stop?" << endl;
        cout << "1. Yes" << endl;
        cout << "0. No" << endl;
        cin >> stop;
        getchar();
    } while(stop == 0);
}

int main() {
    readFile();
    return 1;
}