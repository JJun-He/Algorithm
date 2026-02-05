#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter);
int Sum(string a);

int main()
{
    int answer = 0;
    string ab;
    cin >> ab;
    vector<string> str = split(ab, '-');

    for(int i = 0; i < str.size(); i++){
        int temp = Sum(str[i]);
        if(i == 0){
            answer = answer + temp;
        }
        else{
            answer = answer - temp;
        }
    }

    cout << answer << "\n";
}

vector<string> split(string input, char delimiter){
    vector<string> result;
    stringstream st(input);
    string split;

    while(getline(st, split, delimiter)){
        result.push_back(split);
    }

    return result;
}

int Sum(string a){
    int sum = 0;
    vector<string> temp = split(a, '+');

    for(int i = 0; i < temp.size(); i++){
        sum += stoi(temp[i]);
    }

    return sum;
}