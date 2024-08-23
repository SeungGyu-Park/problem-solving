import java.io.*;
import java.util.*;
 
public class Solution {
    static int n, res;
	static int[][] pos;
	static boolean[] vis;
	
	// 순열 + dfs
	static void dfs(int cnt, int sum, int idx) {
		if (sum >= res) return;
		if (cnt == n) {
			res = Math.min(sum + getDist(idx, 1), res);
			return ;
		}
		for (int i = 2; i < n + 2; i++) {
			if (vis[i]) continue;
			vis[i] = true;
			dfs(cnt + 1, sum + getDist(i, idx), i);
			vis[i] = false;
		}
	}
	
	static int getDist(int idx1, int idx2) {
		return Math.abs(pos[idx1][0] - pos[idx2][0]) + Math.abs(pos[idx1][1] - pos[idx2][1]);
	}
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
 
        int tc = Integer.parseInt(br.readLine());
        
        for (int t = 1; t <= tc; t++) {
        	n = Integer.parseInt(br.readLine());
            pos = new int[n+2][2];
            vis = new boolean[n + 2];
            
            StringTokenizer stk = new StringTokenizer(br.readLine());
            
            for (int i= 0; i < n + 2;i++) {
            	pos[i][0] = Integer.parseInt(stk.nextToken());
            	pos[i][1]= Integer.parseInt(stk.nextToken());
            }
            
            res = Integer.MAX_VALUE;
            dfs(0, 0, 0);
            
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        bw.write(sb.toString());
        br.close();
        bw.close();
    }
}