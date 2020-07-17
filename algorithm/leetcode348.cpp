class TicTacToe {
	vector<vector<int>> R;
    vector<vector<int>> C;
    vector<int> X45;//45度对角线
    vector<int> X135;//135度对角线
    int N;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
    	N = n;
    	R = vector<vector<int>> (2,vector<int>(n,0));
    	C = vector<vector<int>> (2,vector<int>(n,0));
    	X45 = vector<int> (2,0);//45度对角线
    	X135 = vector<int> (2,0);//135度对角线
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
    	if(row == col)
    		X45[player-1]++;
    	if(row+col == N-1)
    		X135[player-1]++;
    	R[player-1][row]++;
    	C[player-1][col]++;
    	if(R[player-1][row]==N || C[player-1][col]==N 
    		|| X45[player-1]==N || X135[player-1]==N)
    		return player;
    	return 0;
    }
};