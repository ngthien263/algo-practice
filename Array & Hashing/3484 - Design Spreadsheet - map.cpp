using namespace std;
class Spreadsheet {
public:
	unordered_map<string, int> umap;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        umap[cell] = value;
    }
    
    void resetCell(string cell) {
        umap[cell] = 0;
    }
    
    int getValue(string formula) {
        int p = formula.find('+');
        string fcell = formula.substr(1, p - 1);
        string scell = formula.substr(p + 1);
        int f_num = (fcell[0] >= 'A' && fcell[0] <= 'Z') ? umap[fcell] : stoi(fcell);
        int s_num = (scell[0] >= 'A' && scell[0] <= 'Z') ? umap[scell] : stoi(scell);
        return f_num + s_num;
    }
};