#include<bits/stdc++.h>
using namespace std;


bool isvalid(vector<vector<int> > &board,int i,int j,int val){
    for(int k=0;k<9;k++)
    {
    if(board[i][k]==val || board[k][j]==val)
    return 0;
    if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k% 3] == val)
      return 0;
    }
    return 1;
}

void solve(vector<vector<int> > &board,string &s){
    if(s=="11")return ;
    int i,j;
    for(i=0;i<9;i++){
	    int z=0;
        for(j=0;j<9;j++)if(board[i][j]==0){
		z=1;break;
	}
	if(z)break;
    }

    if(i>=9 && j>=9){s="11";return ;}

    for(int val=1;val<=9;val++){
        if(isvalid(board,i,j,val)){
            board[i][j]=val;
            solve(board,s);
        }
        if(s=="11")return ;
        else board[i][j]=0;
    }
}


int main(){
        vector<vector<int> >board(9,vector<int>(9));
        for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        cin>>board[i][j];
        string s="00";
        solve(board,s);

        if(s=="00"){
            cout<<"we regret to inform you that , there is no solution for your input ";
            return 0;
        }

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)cout<<board[i][j]<<" ";
            cout<<"\n";
        }
}
