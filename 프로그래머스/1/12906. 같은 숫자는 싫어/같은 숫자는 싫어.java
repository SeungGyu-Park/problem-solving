import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        List<Integer> res = new ArrayList<>();
        int idx = 1;
        int n = arr.length;
        int prev = arr[0];
        
        res.add(prev);
        while (idx < n) {
            int cur = arr[idx];
            if (prev != cur) {
                res.add(cur);
                prev = cur;
            }
            idx++;
        }
        
        int[] answer = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            answer[i] = res.get(i);
        }
        return answer;
    }
}