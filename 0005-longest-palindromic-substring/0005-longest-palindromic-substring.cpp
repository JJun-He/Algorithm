#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";

        int start = 0; // 가장 긴 회문 시작 인덱스
        int maxLen = 0; // 가장 긴 회문의 길이 

        for(int i = 0; i < s.length(); i++) {
            // 1. 홀수 길이 회문 탐색 
            int len1 = expandAroundCenter(s, i, i);
            // 2. 짝수 길이 회문 탐색 
            int len2 = expandAroundCenter(s, i , i+1);

            // 둘 중 더 긴 회문 길이 선택
            int len = max(len1, len2);

            // 기존 최대 길이보다 긴 회문을 찾을 경우 위치 갱신
            if(len > maxLen) {
                maxLen = len;
                // 현재 중심 i와 길이 len을 이용해 시작 위치 계산
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }

private:
    // 중심에서부터 회문 길이를 측정하는 함수
    int expandAroundCenter(const string&s, int left, int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        // 반복문 탈출 시 left와 right 탈출 시 회문 범위를 1칸씩 벗어나 
        // 실제 회문 길이는 (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }

};




