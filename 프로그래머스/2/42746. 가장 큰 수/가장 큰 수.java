import java.util.Arrays;

class Solution {
    public String solution(int[] numbers) {
        // 1. 숫자를 문자열로 반환
        String arr[] = new String[numbers.length];
        
        for(int i = 0; i < numbers.length; i++) {
            arr[i] = String.valueOf(numbers[i]);
        }
        
        // 2. 앞뒤로 붙였을때 더 큰 수가 되는 순서로 정렬
        Arrays.sort(arr, (a, b) -> (b + a).compareTo(a + b));
        
        // 3. 전부 0이면 "000" 대신 "0" 반환
        if(arr[0].equals("0")){
            return "0";
        }
        
        // 4. 정렬된 숫자면 이어붙이기
        return String.join("", arr);
    }
}