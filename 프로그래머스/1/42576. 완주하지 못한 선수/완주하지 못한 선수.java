import java.util.Arrays;

class Solution {
    public String solution(String[] participant, String[] completion) {
        // 1. 두 배열을 이름 순으로 정렬
        Arrays.sort(participant);
        Arrays.sort(completion);
        
        // 2. 완주자 수만큼 비교
        for(int i = 0; i < completion.length; i++) {
            if(!participant[i].equals(completion[i])) {
                return participant[i];
            }
        }
        
        // 3. 전부 같다면 마지막 참가자가 정답
        return participant[participant.length - 1];
    }
}