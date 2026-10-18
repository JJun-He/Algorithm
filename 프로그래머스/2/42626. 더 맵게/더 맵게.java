import java.util.PriorityQueue;

class Solution {
    public int solution(int[] scoville, int K) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        
        // 1. 모든 음식 넣기
        for(int s : scoville) {
            pq.add((long) s);
        }
        
        int count = 0;
        
        // 2. 가장 먼 매운 음식이 k보다 작으면 계속 섞기
        while(pq.peek() < K) {
            // 음식이 하나뿐이면 더 섞을 수 없음
            if(pq.size() < 2) {
                return -1;
            }
            
            long first = pq.poll();
            long second = pq.poll();
            
            pq.add(first + second * 2);
            count++;
        }
        
        return count;
    }
}