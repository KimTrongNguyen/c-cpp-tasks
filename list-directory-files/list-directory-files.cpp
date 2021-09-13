#include <iostream>
#include <dirent.h>

using namespace std;

void printFileList() {
    string directoryPath;
    cout << "Enter the directory path: ";
    cin >> directoryPath;
    getchar();
    DIR* directory = opendir(directoryPath.c_str());
    struct dirent* directoryItem;
    while (directoryItem = readdir(directory)) {
        cout << directoryItem->d_name << endl;
    }
    closedir(directory);
}

int main() {
    int stop = 1;
    do {
        printFileList();
        cout << "Stop?" << endl;
        cout << "1. Yes" << endl;
        cout << "0. No" << endl;
        cin >> stop;
        getchar();
    } while (stop == 0);
    return 0;
}