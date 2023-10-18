#include <string>
#include <iostream>
#include <vector>

using namespace std;

int dx[8] = {-1,-1,-1,0,1,1,1,0};
int dy[8] = {-1,0,1,1,1,0,-1,-1};

int solution(vector<string> board) {
    int oCount = 0, xCount = 0;
    int oWin = 0, xWin = 0;
    
    for (int i = 0; i < board.size(); i++) {
        for (int j= 0; j < board[i].size(); j++) {
            if (board[i][j] == '.') continue;
            if (board[i][j] == 'O') {
                oCount++;
            }
            else if (board[i][j] == 'X') xCount++;
            
            char cur = board[i][j];
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                int nnx = i + dx[dir + 4];
                int nny = j + dy[dir + 4];
                
                if (nx < 0 || nx >=3 || ny < 0 || ny >= 3) continue;
                if (nnx < 0 || nnx >=3 || nny < 0 || nny >= 3) continue;
                if (board[nx][ny] == '.' || board[nnx][nny] == '.') continue;
                if (board[nx][ny] == cur && board[nnx][nny] == cur) {
                    if (cur == 'O') oWin = 1;
                    else xWin = 1;
                }
            }
        }
    }
    cout << oWin << " " << xWin << "\n";
    cout << oCount << " " << xCount << "\n";
    if (oCount == 0 && xCount == 0) return 1;
    if (oCount < xCount) return 0;
    if (oCount >= xCount + 2) return 0;
    if (oCount > xCount && xWin) return 0;
    if (oCount == xCount && oWin) return 0;
    return 1;
}