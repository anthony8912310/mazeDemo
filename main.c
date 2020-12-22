#include <stdio.h>
#include <stdlib.h>

void find_path(const char * const, int, int, char * const);
/* This is what you need to do. Your work is to implement this function */
int up(const char * const, int, int, int,int);
int down(const char * const, int, int, int,int);
int left(const char * const, int, int, int,int);
int right(const char * const, int, int, int,int);
void find_path(const char * const maze, int m, int n, char * const result_maze)
{
    int i=m-1,j=0,lastStep[100],count=0;
    int path[m][n][4];
    int haveGone[m][n];
    
    //haveGone[i][j]=1;
    *(result_maze+i*n+j)='2';
    //Initialization
    for (int p=0;p<m; p++)
    for (int q=0; q<n; q++)
    for (int r=0; r<4; r++)
        path[p][q][r]=0;
    
    for (int p=0;p<m; p++)
    for (int q=0; q<n; q++)
        haveGone[p][q]=0;
    
    while (1)
    {
        //debug
        printf("現在位置：%d %d\n",i+1,j+1);
        
        if (i==0&&j==n-1)
        {
            printf("到達終點\n");
            break;
        }
        
        //check_path
        if (up(maze, i, j, m,n))
        {
            path[i][j][0]=1;
            printf("可以往上走\n");
        }
        if (right(maze, i, j, m,n))
        {
            path[i][j][1]=1;
            printf("可以往右走\n");
            
        }
        if (down(maze, i, j, m,n))
        {
            path[i][j][2]=1;
            printf("可以往下走\n");
        }
        if (left(maze, i, j, m,n))
        {
            path[i][j][3]=1;
            printf("可以往左走\n");
        }
        
        //find_path
        if (path[i][j][0]==1&&haveGone[i-1][j]==0) //上面可以走&&上面還沒走過
        {
            i--; //往上走
            haveGone[i][j]=1;//標記往上走過了
            *(result_maze+i*n+j)='2';
            printf("往上走\n");
            lastStep[count]=1;
            count++;
        }else if (path[i][j][1]==1&&haveGone[i][j+1]==0)
        {
            j++;
            haveGone[i][j]=1;
            *(result_maze+i*n+j)='2';
            printf("往右走\n");
            lastStep[count]=2;
            count++;
        }else if (path[i][j][2]==1&&haveGone[i+1][j]==0)
        {
            i++;
            haveGone[i][j]=1;
            *(result_maze+i*n+j)='2';
            printf("往下走\n");
            lastStep[count]=3;
            count++;
        }else if (path[i][j][3]==1&&haveGone[i][j-1]==0)
        {
            j--;
            haveGone[i][j]=1;
            *(result_maze+i*n+j)='2';
            printf("往左走\n");
            lastStep[count]=4;
            count++;
        }
        else
        {
            count--;
            *(result_maze+i*n+j)='0';
            if (count<0)
            {
                printf("無路可走\n");
                *result_maze='X';
                break;
            }
            
            if (lastStep[count]==1)
            {
                printf("往下走\n");
                i++;
            }else if (lastStep[count]==2)
            {
                printf("往左走\n");
                j--;
            }else if (lastStep[count]==3)
            {
                printf("往上走\n");
                i--;
            }else if (lastStep[count]==4)
            {
                printf("往右走\n");
                j++;
            }
        }
        printf("lastStep[%d]=%d\n",count-1,lastStep[count-1]);
        
        
        printf("\n\n");
    }
}
//上右下左
int up(const char * const maze,int i,int j,int m,int n)
{
    if (*(maze+(i-1)*n+j)=='0'&&(i-1)>=0&&(i-1)<m)
    {
        return 1;
    }
    else return 0;
}
int right(const char * const maze,int i,int j,int m,int n)
{
    if(*(maze+i*n+j+1)=='0'&&(j+1)>=0&&(j+1)<n)
    {
        return 1;
    }
    else return 0;
}
int down(const char * const maze,int i,int j,int m,int n)
{
    if (*(maze+(i+1)*n+j)=='0'&&(i+1)>=0&&(i+1)<m)
    {
        return 1;
    }
    else return 0;
}
int left(const char * const maze,int i,int j,int m,int n)
{
    if(*(maze+i*n+j-1)=='0'&&(j-1)>=0&&(j-1)<n)
    {
        return 1;
    }
    else return 0;
}




int main(void){
  int m, n;

  scanf("%d %d", &m, &n); // Input maze size

  char *maze = (char*)malloc(sizeof(char)*m*n);
  char *result_maze = (char*)malloc(sizeof(char)*m*n);

  /*------- Initialize the two pathays ------*/
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++){
      *(maze+i*n+j) = '0';
      *(result_maze+i*n+j) = '0';
    }
  /*---------------------------------------*/


  /*--------- Input the maze pathay --------*/
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
      scanf("\n%c", (maze+i*n+j));
  /* --------------------------------------*/

    

  /*-------- Find out the maze path -------*/
  find_path(maze, m, n, result_maze);
  /*---------------------------------------*/


  /*----------- output result -------------*/
  if('X'==*result_maze)
    printf("No way\n");
  else{
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++)
          printf("%c",*(result_maze+i*n+j));
      printf("\n");
    }
  }
  /*---------------------------------------*/

  return 0;
}





