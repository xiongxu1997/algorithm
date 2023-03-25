#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    string s = "abc";
    char* c = new char[s.length()+1];
    strcpy(c, s.c_str());
    c[s.length()] = '\0';

    cout<< c << endl;
    cout<< *c <<endl;
    cout<< &c <<endl;
    char** str = &c;
    cout<< *str <<endl;
    cout<< **str <<endl;
    const char* s1 = "#";
    cout<< s1 <<endl;

    vector<int> vector1(10,4);
    cout<<vector1.size()<<endl;
    return 0;
}
