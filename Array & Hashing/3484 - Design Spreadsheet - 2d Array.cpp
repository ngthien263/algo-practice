class Spreadsheet {
public:
    vector<vector<int>> sheet;
	int col;
	int row;
    Spreadsheet(int rows) {
        sheet.assign(rows + 1, vector<int>(26,0));
    }
	
    void setCell(string cell, int value) {
    	col = cell[0] - 'A';
        row = stoi(cell.substr(1));
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        col = cell[0] - 'A';
        row = stoi(cell.substr(1));
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
    	size_t p = formula.find("+");
    	string fp = formula.substr(1, p-1);
    	int f_num, s_num;
    	if(fp[0] >= 'A' && fp[0] <= 'Z'){
    		int t_col = fp[0] - 'A';
    		int t_row = stoi(fp.substr(1));
    		f_num = sheet[t_row][t_col];
		}
    	else f_num = stoi(fp);
    	
    	string sp = formula.substr(p+1);
    	if(sp[0] >= 'A' && sp[0] <= 'Z'){
    		int s_col = sp[0] - 'A';
    		int s_row = stoi(sp.substr(1));
    		s_num = sheet[s_row][s_col];
		}
    	else s_num = stoi(sp);
        return f_num + s_num;
    }
};