#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

using namespace std;

void listChildDirectory(string directoryPath, int tier) {
    DIR* directory;
    struct dirent* directoryItem;
    string childDirectoryPath;
    struct stat itemStat;
    string currentDirectory = ".";
    string previousDirectory = "..";
    if ((directory = opendir(directoryPath.c_str())) != NULL) {
        while ((directoryItem = readdir(directory)) != NULL) {
            stat((directoryPath + "/" + directoryItem->d_name).c_str(), &itemStat);
            if (S_ISDIR(itemStat.st_mode)) {
                //This item is a directory
                if (currentDirectory.compare(directoryItem->d_name) != 0 && previousDirectory.compare(directoryItem->d_name) != 0) {
                    for (int i = 0; i < tier; i++) {
                        cout << "---";
                    }
                    cout << directoryItem->d_name << endl;
                    childDirectoryPath = directoryPath + "/" + directoryItem->d_name;
                    listChildDirectory(childDirectoryPath, (tier + 1));
                }
            } else {
                //This item is a file
                for (int i = 0; i < tier; i++) {
                    cout << "---";
                }
                cout << directoryItem->d_name << endl;
            }
        }
        closedir(directory); 
    }
}

void listDirectoryRecursively() {
    int keepGoing = 1;
    string directoryPath, childDirectoryPath;
    DIR* directory;
    struct dirent* directoryItem;
    struct stat itemStat;
    string currentDirectory = ".";
    string previousDirectory = "..";
    do {
        cout << "Enter the directory path: ";
        //Let user enter white space
        getline(cin >> ws, directoryPath);
        cout << "Directory path: " << directoryPath << endl;
        //Read directory
        if ((directory = opendir(directoryPath.c_str())) != NULL) {
            while ((directoryItem = readdir(directory)) != NULL) {
                stat((directoryPath + "/" + directoryItem->d_name).c_str(), &itemStat);
                if (S_ISDIR(itemStat.st_mode)) {
                    //This item is a directory
                    if (currentDirectory.compare(directoryItem->d_name) != 0 && previousDirectory.compare(directoryItem->d_name) != 0) {
                        cout << directoryItem->d_name << endl;
                        childDirectoryPath = directoryPath + "/" + directoryItem->d_name;
                        listChildDirectory(childDirectoryPath, 1);
                    }
                } else {
                    //This item is a file
                    cout << directoryItem->d_name << endl;                    
                }
            }
            closedir(directory);
        } else {
            //Can't open directory
            cout << "Can not open directory!" << endl;
            cout << strerror(errno) << endl;
        }
        cout << "Continue or exit?" << endl;
        cout << "1. Continue" << endl;
        cout << "0. Exit" << endl;
        cin >> keepGoing;
        getchar();
    } while (keepGoing == 1);
}

int main() {
    listDirectoryRecursively();
    return 0;
}