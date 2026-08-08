#include <iostream>

using namespace std;

class Solution {

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        // 항상 nums1이 더 짧은 배열이 되도록
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while(low <= high) {
            // nums1의 파티션 위치
            int partitionX = low + (high - low) / 2;
            // nums2의 파티션 위치
            int partitionY = (m + n + 1) / 2 - partitionX;

            // 경계값 처리
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ?  INT_MAX : nums2[partitionY];

            // 올바른 분할을 찾은 경우
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                // 전체 원소의 개수가 홀수
                if((m + n) % 2 != 0){
                    return (double)max(maxLeftX, maxLeftY);
                }
                // 전체 원소의 개수가 짝수
                else {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                }
            }
            // 왼쪽 부분이 너무 큼 -> 파티션을 왼쪽으로 이동
            else if (maxLeftX > minRightY) {
                high = partitionX - 1;
            }
            // 왼쪽 부분이 너무 작음 -> 파티션을 오른쪽으로 이동 
            else {
                low = partitionX + 1;
            }
        }

        return 0.0;
    }
};