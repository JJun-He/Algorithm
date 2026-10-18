class Solution {
    public long solution(int n, int[] times) {
        long left = 1;
        
        // 첫 번째 심사관 혼자 n명을 처리해도 충분한 시간
        long right = (long) times[0] * n;
        
        while(left < right) {
            long mid = left + (right - left) / 2;
            
            // mid분 동안 심사할 수 있는 사람 수 
            long people = 0;
            
            for(int time : times) {
                people += mid / time;
                
                // n명이상 가능하다는 걸 확인햇으면 중단
                if (people >= n) {
                    break;
                }
            }
            
            if (people >= n) {
                right = mid; // 가능 
            } else {
                left = mid + 1; // 부족
            }
        }
        
        return left;
    }
}