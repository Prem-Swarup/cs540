/*
Coded by
Prem Swarup
*/

#include <bits/stdc++.h>

using namespace std;
namespace fs = std::filesystem;



const string currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y%m%d_%X", &tstruct);

    return buf;
}


class NamingManager {
private:
    string currentDirectoryPath;
    const int MAX_FILE_PATH_LENGTH = 260;
    const int MAX_NAMING_LENGTH = 255;

public:
    NamingManager();
    NamingManager(string path);
    void changeDirectoryPath(string path) ;
    void createNames(bool isFolder = false);
    void createNames(string baseName, bool isFolder = false);
    bool isFilePathLengthExceedsLimit(string fullPath);
    bool isNamingLengthExceedsLimit(string name);
    string generateUniqueName(string fullName, bool isFolder = false);
};

NamingManager::NamingManager() {
    currentDirectoryPath = "./";
}

NamingManager::NamingManager(string path) {
    currentDirectoryPath = path;
}

void NamingManager::changeDirectoryPath(string path) {
    currentDirectoryPath = path ;
}

void NamingManager::createNames(bool isFolder) {
    string baseName = isFolder ? "new_folder" : "new_file";
    string currentTime = currentDateTime() ;
    string fullName = baseName + "_" + currentTime;

    string fullPath = fs::path(currentDirectoryPath) / fullName;

    if (isFilePathLengthExceedsLimit(fullPath)) {
        cout << "Error: Full path length exceeds limit." << endl ;
        cout << "Please make sure Full path length have less than " ;
        cout << MAX_FILE_PATH_LENGTH+1 << "characters" << endl ;
        return;
    }

    if (fs::exists(fullPath)) {
        fullName = generateUniqueName(fullName, isFolder);
        fullPath = fs::path(currentDirectoryPath) / fullName;
    }

    if (isFolder) {
        fs::create_directories(fullPath);
        cout << "Created folder " << fullName << endl;
    } else {
        ofstream file(fullPath);
        file.close();
        cout << "Created file " << fullName << endl;
    }
}

void NamingManager::createNames(string baseName, bool isFolder) {

    string fullName = baseName;
    string fullPath = fs::path(currentDirectoryPath) / fullName;

    if (isNamingLengthExceedsLimit(baseName)) {
        cout << "Error: Naming length exceeds limit." << endl ;
        cout << "Please make sure file name have less than " ;
        cout << MAX_NAMING_LENGTH + 1 << "characters" << endl ;
        return;
    }

    if (isFilePathLengthExceedsLimit(fullPath)) {
        cout << "Error: File path length exceeds limit." << endl;
        cout << "Please make sure Full path length have less than " ;
        cout << MAX_FILE_PATH_LENGTH+1 << "characters" << endl ;
        return;
    }

    if (fs::exists(fullPath)) {
        fullName = generateUniqueName(fullName, isFolder);
        fullPath = fs::path(currentDirectoryPath) / fullName;
    }

    if (isFolder) {
        fs::create_directories(fullPath);
        cout << "Created folder " << fullName << endl;
    } else {
        ofstream file(fullPath);
        file.close();
        cout << "Created file " << fullName << endl;
    }
}

bool NamingManager::isFilePathLengthExceedsLimit(string fullPath) {
    return (fullPath.length() > MAX_FILE_PATH_LENGTH);
}

bool NamingManager::isNamingLengthExceedsLimit(string name) {
    return (name.length() > MAX_NAMING_LENGTH);
}

string NamingManager::generateUniqueName(string baseName, bool isFolder) {
    int count = 1;
    string newName = baseName;

    while (fs::exists(fs::path(currentDirectoryPath) / newName)) {
        newName = baseName + "_" + to_string(count);
        count++;
    }

    return newName;
}


int main() {
    NamingManager manager;
    int n ;
    char q ;
    string customName ;

    while(true) {
        cout << "Choose what you want to do:\n" ;
        cout << "1. Create a filename\n" ;
        cout << "2. Create a foldername\n" ;
        cout << "3. Exit\n" ;
        cin >> n ;
        

        switch(n) {
            case 1: 
                cout << "Want to create file with custom name (y/n): " ;
                cin >> q ;
                if(q == 'y' || q == 'Y') { 
                    cout << "Enter custom name: " ;
                    cin >> customName ;
                    manager.createNames(customName) ;
                } else if(q == 'n' || q == 'N'){
                    manager.createNames() ; 
                } else {
                    cout << "Wrong Input" << endl ;
                }
                break ;
            
            case 2:
                cout << "Want to create folder with custom name (y/n): " ;
                cin >> q ;
                if(q == 'y' || q == 'Y') {
                    cout << "Enter custom name: " ;
                    cin >> customName ;
                    manager.createNames(customName, true) ;
                } else if(q == 'n' || q == 'N'){
                    manager.createNames(true) ; 
                } else {
                    cout << "Wrong Input" << endl ;
                }
                break ;

            case 3:
                return 0 ;

            default:
                cout << "Please enter 1 2 or 3 only" << endl ;
                break ;
        }

        cout<<endl ;
    }

    return 0;
}
