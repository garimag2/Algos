#include <bits/stdc++.h>

using namespace std;

void print_vector(vector<vector<int>> board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
vector <string> convert_string(vector<vector<int>> board){
    vector<string> out(board.size(),"");
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==0){
                out[i].push_back('.');
            }
            else{
                out[i].push_back('O');
            }
        }
    }
    return out;
}
vector <string> iterate_once(vector<vector<int>> board, int n){
    int b=1;
    while(b<(n+1)){
        if(b==1){
            b+=1;
            continue;
        }
        if(b==2 || b==4){
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++){
                    board[i][j]+=1;
                }
            }
            b++;
        }
        if(b==3 || b==5){
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++){
                    if(board[i][j]==2){
                        board[i][j]=0;
                        if(i>0 && board[i-1][j]!=2){
                            board[i-1][j]=0;
                        }
                        if(i<board.size()-1 && board[i+1][j]!=2){
                           board[i+1][j]=0;
                        }
                        if(j<board[i].size()-1 && board[i][j+1]!=2){
                            board[i][j+1]=0;
                        }
                        if(j>0 && board[i][j-1]!=2){
                            board[i][j-1]=0;
                        }
                    }
                }
                //cout << i << endl;
                //print_vector(board);
            }
            b++;
        }
    }
    //print_vector(board);
    return convert_string(board);
    
}
vector <string> bomberMan(int n, vector <string> grid) {
    // Complete this function
    vector <vector <int>> board(grid.size(),vector <int>(grid[0].length(),0));
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].length();j++){
            if(grid[i][j]=='O'){
                board[i][j]=1;
            }
            else{
                board[i][j]=0;
            }
        }
    }
    //cout << "Original" << endl;
    //print_vector(board);
    vector<string> all_o(grid.size(),"");
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            all_o[i].push_back('O');
        }
    }
    /*if(n>4){
        n=4+n%4;
    }*/
    //cout << n << endl;
    if(n==1){
        return grid;
    }
    else if(n%2==0){
        return all_o;
    }
    if(n==3){
        return iterate_once(board,3);
    }
    else if((n%4==3)){
        return iterate_once(board, 3);
    }
    else if((n%4==1)){
        //cout <<"Hey" << endl;
        return iterate_once(board,5);
        
    }
    //print_vector(board);
    return grid;
}

int main() {
    int r;
    int c;
    int n;
    cin >> r >> c >> n;
    vector<string> grid(r);
    for(int grid_i = 0; grid_i < r; grid_i++){
       cin >> grid[grid_i];
    }
    vector <string> result = bomberMan(n, grid);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
