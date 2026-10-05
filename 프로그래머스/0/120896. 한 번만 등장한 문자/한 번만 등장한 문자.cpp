#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int freq[26] = {0};
    for(char c: s) freq[c - 'a']++;
    
    string result;
    for(int i = 0; i < 26; i++) {
        if(freq[i] == 1) result += ('a' + i);
    }
    
    return result;
}