#include <bits/stdc++.h>
using namespace std;
ifstream f("fis.txt");

void afisarev(double v[],double n)
{
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
}

void afisarem(double mat[101][101],double n,double m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

void adunare_vectori(double vector1[],double vector2[],double vector3[],double n)
{
    for(int i=0; i<n; i++)
        vector3[i]=vector1[i]+vector2[i];
}

void scadere_vectori(double vector1[],double vector2[],double vector3[],double n)
{
    for(int i=0; i<n; i++)
        vector3[i]=vector1[i]-vector2[i];
}

void inmultire_vectori(double vector1[],double vector2[],double vector3[],double n)
{
    for(int i=0; i<n; i++)
        vector3[i]=vector1[i]*vector2[i];
}

void impartire_vectori(double vector1[],double vector2[],double vector3[],double n)
{
    for(int i=0; i<n; i++)
        vector3[i]=vector1[i]/vector2[i];
}

void adunare_matrici(double matrice1[101][101], double matrice2[101][101], double n, double m, double matrice3[101][101])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            matrice3[i][j]=matrice1[i][j]+matrice2[i][j];
}

void scadere_matrici(double matrice1[101][101], double matrice2[101][101], double n, double m, double matrice3[101][101])
{
    for(int i=0; i<n; i++)
        for(int j=1; j<m; j++)
            matrice3[i][j]=matrice1[i][j]-matrice2[i][j];
}


void inmultire_matrici(double matrice1[101][101],double matrice2[101][101],double n1,double m1,double n2,double m2, double matriceRezultat[101][101],double &n3,double &m3)
{

    if(m1!=n2)
        cout<<"nu se poate efectua inmultirea";
    for(int i=0; i<n1; i++)
        for(int j=0; j<m2; j++)
            for(int k=0; k<m1; k++)
                matriceRezultat[i][j]+=matrice1[i][k]*matrice2[k][j];
    n3=n1;
    m3=m2;


}

int matrice_la_putere(double matrice1[101][101],double matrice2[101][101],double n,double putere, double matriceRezultat[101][101])
{

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            matrice2[i][j]=matrice1[i][j];

    while(putere>1)
    {
        inmultire_matrici(matrice2,matrice1,n,n,n,n,matriceRezultat,n,n);
        putere--;

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                matrice2[i][j]=matriceRezultat[i][j];

        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                matriceRezultat[i][j]=0;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            matriceRezultat[i][j]=matrice2[i][j];

}

void transpusa_matrice(double matrice[101][101],double n,double m, double matrice_rezultat[101][101])
{
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            matrice_rezultat[j][i]=matrice[i][j];
}

//nefunctionala pt valori mai mari de 3(CHIAR NU STIU DE CE SMR)
double d = 0;
double det(int n, double mat[101][101])
{
    int c, subi, i, j, subj;
    double submat[101][101];
    if (n == 2)
    {
        return( (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
    }
    else
    {
        for(c = 0; c < n; c++)
        {
            subi = 0;
            for(i = 1; i < n; i++)
            {
                subj = 0;
                for(j = 0; j < n; j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    submat[subi][subj] = mat[i][j];
                    subj++;
                }
                subi++;
            }
            d = d + (pow(-1,c) * mat[0][c] * det(n - 1,submat));
        }
    }
    return d;
}

double suma_elemente_vector(double v[101], double n)
{
    double s=0;
    for(int i=0; i<n; i++)
        s+=v[i];
    return s;
}

double produs_elemente_vector(double v[101], double n)
{
    double p=1;
    for(int i=0; i<n; i++)
        p*=v[i];
    return p;
}

void sortare_selectie_directa(double v[101], double n, int tip)// cresc:tip=1; desc:tip=-1
{
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(v[i]*tip>v[j]*tip)
                swap(v[i],v[j]);

}


void sortare_bubble(double v[101], double n, int tip)
{
    int terminat=0;
    while(!terminat)
    {
        terminat=1;
        for(int i=0; i<n-1; i++)
            if(v[i]*tip>v[i+1]*tip)
            {
                int aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                terminat=0;
            }
    }
}

void sortare_insertie(double v[101], double n, int tip)

{

    for(int j=1; j<n; j++)
    {
        double aux=v[j];
        int i=j-1;
        while (aux*tip < v[i]*tip && i>=0)
        {
            v[i+1]=v[i];
            i=i-1;
        }
        v[i+1]=aux;
    }
}

void shiftare(double v[101], double n, int nr_shift,int directie)
{
    double aux;
    while(nr_shift)
    {
        if(directie==1)
        {
            aux=v[0];
            for(int i=0; i<n; i++)
                v[i]=v[i+1];
            v[n-1]=aux;
        }
        else
        {
            aux=v[n-1];
            for(int i=n; i>0; i--)
                v[i]=v[i-1];
            v[0]=aux;
        }
        nr_shift--;
    }
}

void operatii_matrice(double a[101][101], double n, double &ds, double &dp, double &nord, double &sud, double &est, double &vest, double &subdp, double &subds, double &deasupradp, double &deasuprads)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if (i==j) dp+=a[i][j];
            else if (i+j==n+1)
                ds+=a[i][j];
            else if (i>j)
                deasupradp+=a[i][j];
            else
                subdp+=a[i][j];
            if (i+j<n-1)
                deasuprads+=a[i][j];
            if (i+j>n-1)
                subds+=a[i][j];
            if(i>j&&i+j<n-1)
                nord+=a[i][j];
            if(i>j&&i+j>n-1)
                est+=a[i][j];
            if(i<j&&i+j<n-1)
                sud+=a[i][j];
            if(i<j&&i+j>n-1)
                vest+=a[i][j];
        }

}

int main()
{
    double m1[101][101],m2[101][101],m3[101][101],n,m;
    f>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            f>>m1[i][j];

    cout<<det(n,m1)<<endl;

    afisarem(m1,n,m);
    return 0;
}
