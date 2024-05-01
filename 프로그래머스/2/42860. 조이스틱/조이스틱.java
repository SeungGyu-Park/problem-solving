class Solution {
    public int solution(String name) {
        int n = name.length();
        int minMove = n - 1; 

        int answer = 0;

        for (int i = 0; i < n; i++) {
            answer += Math.min(name.charAt(i) - 'A', 'Z' - name.charAt(i) + 1);

            int next = i + 1;
            while (next < n && name.charAt(next) == 'A') {
                next++;
            }

            minMove = Math.min(minMove, i + n - next + Math.min(i, n - next));
        }

        return answer + minMove;
    }
}