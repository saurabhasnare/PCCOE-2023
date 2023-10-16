/*A classic problem that can be solved by backtracking is called the Knight's tour Problem.
It is a problem in which we are provided with a NxN chessboard and a knight. For a
person who is not familiar with chess, the knight moves two squares horizontally and one
square vertically, or two squares vertically and one square horizontally. In this problem,
there is an empty chess board, and a knight starting from any location in the board, our
task is to check whether the knight can visit all of the squares in the board or not. When It
can visit all of the squares, then place the number of jumps needed to reach that location
from the starting point.
*/


import java.util.*;

public class chess{
    static int cnt=0;
    public static int moveKnight(int[][] chessboard,int rowArray[],int colArray[],int row, int col){

            if(chessboard[row][col]==0){
                
                cnt++;
                
                chessboard[row][col]=cnt;

                for(int i=0;i<8;i++){
                    int oldrow=row;
                    int oldcol=col;
                    row+=rowArray[i];
                    col+=colArray[i];

                    if(row>=0 && row<8 && col>=0 && col<8)
                    {
                        if(chessboard[row][col]==0){
                            moveKnight(chessboard, rowArray, colArray, row, col);
                        }
                        
                    } 
                    row=oldrow;
                    col=oldcol;
                    
                }
            }
            
            return cnt;

          //  System.out.println(cnt);

        

    }
    public static void main(String args[]){
      int row[]={2,2,-2,-2,1,1,-1,-1};
      int col[]={1,-1,1,-1,2,-2,2,2};
      
      int chessboard[][] =new int[8][8];

      for(int i=0;i<8;i++){
        //System.out.println("{");
        for(int j=0;j<8;j++){

           chessboard[i][j]=0;
        }

       // System.out.println("}");
    }
      
      // chessboard
     // Arrays.fill(chessboard,0);

      int cnt=moveKnight(chessboard,row,col,0,0);

            for(int i=0;i<8;i++){
                System.out.println("{");
                for(int j=0;j<8;j++){

                    System.out.print(chessboard[i][j]+",");
                }

                System.out.print("}");
            }

            System.out.println("total moves :"+cnt);
    }
}


