#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, int> m;

vector<string> solution(vector<string> players, vector<string> callings) {
    int i = 0;
    for (string p : players) {
        m[p] = i++;
    }
    for (string c : callings) {
        string nxt_player = players[m[c]-1];
        int nxt_idx = m[c]-1;
        int cur_idx = m[c];
        
        players[m[c]] = nxt_player;
        players[nxt_idx] = c;
        m[nxt_player]++;
        m[c]--;
    }
    return players;
}