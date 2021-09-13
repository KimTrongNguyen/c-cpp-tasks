#include <iostream>
#include <fstream>

using namespace std;

void writeFile() {
    int stop = 0;
    string filePath;
    string fileContent;
    fstream file;
    do {
        cout << "Enter the file path: ";
        cin >> filePath;
        getchar();
        cout << "Enter the file content: ";
        //Let user input with white space
        getline(cin >> ws, fileContent);
        //Write file
        file.open(filePath, ios::out | ios::trunc);
        file << fileContent;
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
    writeFile();
    return 1;
}