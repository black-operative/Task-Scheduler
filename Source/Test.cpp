#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream file_reader;
    
    file_reader.open("../Demo-Files/index.html");

    string line;
    while (getline(file_reader, line)) { cout << line << endl; }
    
    file_reader.close();
    return 0;
}