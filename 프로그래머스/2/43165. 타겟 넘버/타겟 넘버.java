class Solution {
    public int solution(int[] numbers, int target) {
        // 0번 숫자부터 시작, 현재 합은 0 
        return dfs(numbers, target, 0, 0);
    }
    
    private int dfs(int[] numbers, int target, int index, int sum) {
        // 모든 숫자를 사용했다면
        if(index == numbers.length) {
            if(sum == target) {
                return 1; // 성공한 경우 1개 
            }
            return 0; // 실패한 경우 
        }
        
        // 현재 숫자를 더하고, 다음 숫자로 이동 
        int plus = dfs(numbers, target, index + 1, sum + numbers[index]);
        
        // 현재 숫자를 빼고, 다음 숫자로 이동
        int minus = dfs(numbers, target, index + 1, sum - numbers[index]);
        
        // 두 방향에서 찾은 성공 횟수를 합산
        return plus + minus;
    }
}