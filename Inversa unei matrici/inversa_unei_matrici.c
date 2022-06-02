#include <stdio.h>
#include <stdlib.h>

void citire_matrice(int M[][100], int row, int col)
{
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            scanf("%d", &M[i][j]);
}

void afisare_matrice(int M[][100], int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            printf("%d", M[i][j]);
        printf("\n");
    }
    printf("\n");
}

int det(int M[][100], int row, int col)
{
    if(row==1 && col==1) return M[0][0];
    else if(row==2 && col==2)
    return M[0][0]*M[1][1]-M[0][1]*M[1][0];
    else if(row==3 && col==3)
    return M[0][0]*M[1][1]*M[2][2] + M[0][1]*M[1][2]*M[2][0] + M[1][0]*M[0][2]*M[2][1] - M[0][2]*M[1][1]*M[2][0] - M[1][2]*M[2][1]*M[0][0] - M[0][1]*M[1][0]*M[2][2];
}

int power(int x, int y)
{
    if(y==0) return 1;
    if(y==1) return x;

    //if(y<0) return 1/power(x, -y);

    int val=x;
    for(int i=2; i<=y; i++)
    val*=x;

    return val;
}

void transpusa(int M[][100], int M_tr[][100], int row, int col)
{
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            M_tr[i][j]=M[j][i];
}

int main()
{
    int row, col;

    int M[100][100];
    int tmp[100][100];

    int M_adj[100][100];
    int M_tr[100][100];

    float M_inversa[100][100];

    freopen("input.txt", "r", stdin);

    scanf("%d%d", &row, &col);

    citire_matrice(M, row, col);

    int determinant=det(M, row, col);

    transpusa(M, M_tr, row, col);

    int x, y;
    int p=0, q=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            x=0;
            y=0;
            for(int k=0; k<row; k++)
            {
                for(int l=0; l<col; l++)
                {
                    if(k==i || l==j)
                        continue;
                    else
                    {
                        tmp[x][y]=M_tr[k][l];
                        y++;
                    }
                }
                if(y) x++;
                y=0;
            }
            M_adj[p][q]=power(-1,i+1+j+1)*det(tmp, row-1, col-1);
            q++;
        }
        q=0;
        p++;
    }

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            M_inversa[i][j]=(1/(float)determinant)*(float)M_adj[j][i];

    printf("\nMatricea adjuncta este:\n");
    afisare_matrice(M_adj, row, col);


    printf("\nMatricea inversa este:\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            printf("%.3f ", M_inversa[i][j]);
        printf("\n");
    }

    system("PAUSE");

    return 0;
}