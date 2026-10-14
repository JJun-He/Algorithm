import java.util.ArrayList;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        
        ArrayList<Integer> result = new ArrayList<>();
        
        int releaseDay = 0; // 현재 묶음의 배포일
        int count = 0; // 현재 묶음의 기능수
        
        for (int i = 0; i < progresses.length; i++) {
            // 1. 완료까지 필요한 날 계산
            int remain = 100 - progresses[i];
            int days = remain / speeds[i];
            
            // 나머지가 있으면 하루 더 필요
            if(remain % speeds[i] != 0){
                days++;
            }
            
            // 2. 현재 배포일보다 늦게 끝나면 새로운 묶음
            if(days > releaseDay) {
                if(count > 0) {
                    result.add(count); // 이전묶음 저장 
                }
                
                releaseDay = days;
                count = 1;
            } else {
                count++;
            }
            
        }
        
        // 3. 마지막 묶음 저장
        result.add(count);
        
        // 4. ArrayList를 int[]로 변환
        int[] answer = new int[result.size()];
        
        for(int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
        
        
    }
}