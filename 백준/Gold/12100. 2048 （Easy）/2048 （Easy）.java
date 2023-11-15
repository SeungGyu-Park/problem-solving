import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int n, board[][], ans = -1;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        board = new int[n][n];
        StringTokenizer stz;

        for (int i = 0; i  <n;i++){
            stz = new StringTokenizer(br.readLine());
            for (int j = 0; j < n;j++) {
                board[i][j] = Integer.parseInt(stz.nextToken());
            }
        }
        go(0);
        System.out.println(ans);
    }

    public static void go(int idx) {
        if (idx == 5) {
            ans = Math.max(ans, findAnswer());
            return ;
        }
        int tmp[][] = new int[21][21];
        copy(tmp);
        for (int i = 0; i < 4;i++){
            pushLeft(i);
            go(idx + 1);
            recover(tmp);
        }
    }

    public static void recover(int tmp[][]) {
        for (int i = 0; i <n;i++){
            for (int j = 0; j <n;j++) {
                board[i][j] = tmp[i][j];
            }
        }
    }
    private static void pushLeft(int dir) {
        
        for (int d = 0; d < dir; d++) rotation();
        for (int i = 0; i <n;i++){
            for (int j = 0; j <n;j++){
                for (int k = j + 1; k < n;k++) {
                    if (board[i][k] == 0) continue;
                    if (board[i][j] == board[i][k]) {
                        board[i][j] *= 2;
                        board[i][k] = 0;
                    }
                    break;
                }
            }
            ArrayList<Integer> al = new ArrayList<>();
            for (int j = 0; j <n;j++){
                if (board[i][j] != 0) al.add(board[i][j]);
            }
            for (int j = 0; j <n;j++){
                if (j < al.size()) board[i][j] = al.get(j);
                else board[i][j] = 0;
            }
        }

    }

    private static void rotation() {
        int tmp[][] = new int[21][21];
        copy(tmp);
        for (int i =0; i <n;i++){
            for (int j = 0;j <n;j++){
                board[j][n-i-1] = tmp[i][j];
            }
        }
    }

    public static void copy(int tmp[][]) {
        for (int i = 0; i <n;i++){
            for (int j = 0; j <n;j++){
                tmp[i][j] = board[i][j];
            }
        }
    }
    public static int findAnswer() {
        int res = 0;
        for (int i = 0; i <n;i++){
            for (int j = 0; j <n;j++){
                res = Math.max(res, board[i][j]);
            }
        }
        return res;
    }
}