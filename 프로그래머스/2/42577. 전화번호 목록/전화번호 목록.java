import java.util.Arrays;

class Solution {
    public boolean solution(String[] phone_book) {
        
        // 1. 문자열 순서로 정렬
        Arrays.sort(phone_book);
        
        // 2. 바로 다음 번호가 현재 번호로 시작하는지 확인
        for(int i = 0; i < phone_book.length - 1; i++) {
            if(phone_book[i + 1].startsWith(phone_book[i])) {
                return false;
            }
        }
        
        return true;
    }   
}