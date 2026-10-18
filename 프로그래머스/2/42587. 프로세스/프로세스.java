import java.util.Queue;
import java.util.ArrayDeque;

class Solution {
    public int solution(int[] priorities, int location) {
        Queue<Integer> queue = new ArrayDeque<>();
        
        // 1. 원래 인덱스를 순서대로 넣기
        for (int i = 0; i < priorities.length; i++) {
            queue.add(i);
        }
        
        int count = 0;
        
        while(!queue.isEmpty()) {
            int current = queue.poll(); // 맨 앞 인덱스 꺼내기
            boolean hasHigher = false;
            
            // 2. 더 높은 우선순위가 남아 있는지 확인
            for(int next : queue) {
                if(priorities[next] > priorities[current]) {
                    hasHigher = true;
                    break;
                }
            }
            
            if(hasHigher) {
                // 3. 더 중요한 게 있으면 뒤로 보내기
                queue.add(current);
            } else {
                // 4. 없으면 실행
                count++;
                
                if(current == location) {
                    return count;
                }
            }
        }
        
        return 0; 
    }
}