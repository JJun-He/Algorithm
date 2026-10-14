class Solution {
    boolean solution(String s) {
        int count = 0;
        
        for(int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            
            
            if(c == '(') {
                count++;
            } else {
                count--;
            }
            
            // 열린 괄호 없이 닫힌 괄호가 나올 수 없음
            if(count < 0) {
                return false;
            }
        }
        
        // 열린 괄호가 전부 닫혔는지 확인 
        return count == 0;
    }
}