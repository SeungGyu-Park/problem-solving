import java.util.*;

class Solution {
    static boolean[] vis;
    static PriorityQueue<Integer> pq;
    
    public int solution(int[] cards) {
        int n = cards.length;
        
        vis = new boolean[n];
        pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(cards, i, 0);
            }
        }
        
        return pq.size() == 1 ? 0 : pq.poll() * pq.poll();
    }
    
    private void dfs(int[] cards, int idx, int cnt) {
        if (vis[idx]) {
            pq.add(cnt);
            return;
        }
        vis[idx] = true;
        dfs(cards, cards[idx]-1, cnt + 1);
    }
}