#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1 = "RohoR";
    int start = 0, end = s1.size() - 1;
    
    while(start < end){
        if(s1[start] != s1[end]){
            // cout << "Not a Palindrome";
            return 0;
        }
        // swap(s1[start], s1[end]);
        start++, end--;
    }
        // cout << "Palindrome";

    // cout << s1 << endl;
    
    int size = 0;
    
    while(s1[size] != '\0'){
        size++;
    }
    
    // cout << size << endl;
    
    for(int i=0; i<s1.size() - 1; i++){
        swap(s1[i], s1[s1.size() - i - 1]);
    }
    
    // cout << s1;
    
    string s2 = "ababab";
    
    cout << s2.find("ab", 0);
    

    return 0;
}