import java.util.ArrayList;

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        
        // 1. 조건 기준과 정렬 기준의 열 변호 찾기
        int extIndex = getIndex(ext);
        int sortIndex = getIndex(sort_by);
        
        // 숫자 배열 하나가 데이터 한 행 
        ArrayList<int[]> result = new ArrayList<>();
        
        // 2. 조건에 맞는 행만 담기
        for(int[] row: data) {
            if(row[extIndex] < val_ext) {
                result.add(row);
            }
        }
        
        // 3. 저장한 열을 기준으로 오름차순 정렬
        result.sort((a, b) -> 
                   Integer.compare(a[sortIndex], b[sortIndex]));
        
        // 4. 리스트를 2차원 배열로 변환
        int[][] answer = new int[result.size()][4];
        
        for(int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
    
    
    
    // 이름을 열 번호로 바꾸는 메소드
    private int getIndex(String name) {
        if(name.equals("code")) return 0;
        if(name.equals("date")) return 1;
        if(name.equals("maximum")) return 2;
        return 3;
    }
}