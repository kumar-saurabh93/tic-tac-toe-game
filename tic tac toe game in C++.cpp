#include <bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#define MIN_BALANCE 500
#include<iostream>
#include<malloc.h>
#include<cstdio>
#include<typeinfo>
#include<exception>
#include<conio.h>

using namespace std;

void fillboard(int,int**,int ,int);
int check_diagonal(int **,int);
int check_column_for_X(int **,int,int);
int check_column_for_O(int **,int,int);
int check_row_for_X(int **,int,int);
int check_row_for_O(int **,int,int);
int check_check(int **,int *,int);
void display_board(int **,int);
int board_filled(int**,int);
int main ()
{
int n;
cout<<"enter size of board"<<endl;
cin>>n;
cout<<"player 1 enter your name"<<endl;
string s1,s2;
cin>>s1;
cout<<"player 2 enter your name"<<endl;
cin>>s2;
int result=0;
    int **board=(int**)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
        board[i]=(int*)calloc(sizeof(int),n);
  system("cls");
   int flag=1;
   for(int i=0; ;i++)
   {
       int entry;
       display_board(board,n);
       if(flag)
       cout<<s1<<" : enter your choice"<<endl<<endl;
       else
       cout<<s2<<" : enter your choice"<<endl<<endl;
       cin>>entry;

       fillboard(entry,board,n,flag);
       flag=1-flag;
       if(board_filled(board,n))
        {system("cls");display_board(board,n);cout<<endl<<"match draw";break;}
       if(check_check(board,&result,n)==1)
                {system("cls");display_board(board,n);cout<<endl<<s1<<" won";break;}
       if(check_check(board,&result,n)==2)
              {system("cls");display_board(board,n);cout<<endl<<s2<<" won";break;}
            system("cls");
   }
getch();
}
int board_filled(int **board,int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(board[i][j]==0)
                return 0;

    return 1;
}
void display_board(int **board,int n)
{
    int xx=0;
    for(int i=0;i<n;i++)
    {
      cout<<"| ";
     for(int j=0;j<n;j++)
        {
         if(board[i][j]==0)
            cout<<"("<<xx++<<")"<<"      "<<" "<<"| ";
         else
            printf("(%d) %5c | ",xx++,board[i][j]);
        }
        cout<<endl<<endl;
    }
}
int check_check(int **board,int *result,int n)
{
int check1=0,check2=0;
for(int i=0;i<n;i++)
{
    if(board[i][0]=='X')
     check1=  (check_row_for_X(board,i,n));
    else if(board[i][0]=='O')
       check2= (check_row_for_O(board,i,n));

       if(check1==1){*result =1;break;}
       else if(check2==2){*result =2; break;}


        if(board[0][i]=='X')
     check1=  (check_column_for_X(board,i,n));
    else if(board[0][i]=='O')
       check2= (check_column_for_O(board,i,n));

         if(check1==1){*result =1;break;}
       else if(check2==2){*result =2; break;}

}
if(check1==0&&check2==0)
{
    int x=check_diagonal(board,n);
    if(x==1)*result=1;
    else if(x==2)*result =2;
}
return (*result);
}


int check_row_for_O(int **board,int i,int n)
{
 for(int j=0;j<n;j++)
 {
   if(board[i][j]!='O')
        return 0;
 }
 return 2;
}

int check_row_for_X(int **board,int i,int n)
{
   for(int j=0;j<n;j++)
 {
   if(board[i][j]!='X')
        return 0;
 }
 return 1;
}

int check_column_for_O(int **board,int i,int n)
{
 for(int j=0;j<n;j++)
 {
   if(board[j][i]!='O')
        return 0;
 }
 return 2;
}

int check_column_for_X(int **board,int i,int n)
{
 for(int j=0;j<n;j++)
 {
   if(board[j][i]!='X')
        return 0;
 }
 return 1;
}
int check_diagonal(int **board,int n)
{
    if(board[0][0]=='X')
    {
        int i;
        for(i=0;i<n;i++)
            if(board[i][i]!='X')
                break;
         if(i==n)return 1;
    }
    else if(board[0][0]=='O')
    {
        int i;
        for(i=0;i<n;i++)
            if(board[i][i]!='O')
                break;
            if(i==n)return 2;

    }

    if(board[n-1][n-1]=='X')
    {
        int i;
        for(i=n-1;i>=0;i--)
            if(board[i][i]!='X')
                break;
            if(i==-1)return 1;
    }
    else if(board[n-1][n-1]=='O')
    {
        int i;
        for(i=n-1;i>=0;i--)
            if(board[i][i]!='O')
            break;
        if(i==-1)return 2;
    }
  return 0;
}
void fillboard(int entries,int** board,int n,int flag)
{
 int row= entries/n;
 int column=entries%n;
 if(board[row][column]==0)
    (flag==1)?(board[row][column]='X'):(board[row][column]='O');
  }
