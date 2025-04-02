#include <iostream>
using namespace std;

void printSubsets(string str, string curr, int index){
    if(index == str.size()){
        cout << curr << " ";
	return;
    }
    printSubsets(str, curr, index + 1); // skip curr char
    printSubsets(str, curr + str[index], index + 1); // add curr  char
}

int main () {
    string str = "AB";
    printSubsets(str, "", 0);
}