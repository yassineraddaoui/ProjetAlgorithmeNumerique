#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<time.h>
int SaisieN(){
    int x;
    printf("donner N\n");
    scanf("%d",&x);
    return x;
}
int SaisieX(){
    int x;
    printf("donner X\n");
    scanf("%d",&x);
    return x;
}
//RANDOM -100 et 100 .
float RandomNumber(){
    srand(time(0));
    int signe=rand()%2;
    if( signe==0)
        return rand()%100 ;
    else
        return -1*(rand()%100);
}
void Affiche_V(float *vect,unsigned n){
    int i;
    for(i=0;i<n;i++){
        printf("%f\n",vect[i]);


    }
    printf("\n");
}
//Remplir Matrice demi Bande
void Saisie_M(float **mat,unsigned n,unsigned m){

    unsigned i,j ;

    for(i=0 ;i<n-m-1 ;i++){
        for(j=i+1 ; j<=i+m ; j++){
            mat[i][j]=RandomNumber();
            mat[i][i]+=mat[i][j]+1;
        }
    }

    for(i=n-m-1 ;i<n ;i++){
        for(j=i+1 ; j<n ; j++){
            mat[i][j]=RandomNumber();
            mat[i][i]+=mat[i][j]+2;
        }
    }

    for(i=1 ;i<=m ;i++){
        for(j=0 ; j< i ; j++){
            mat[i][j]=RandomNumber();
            mat[i][i]+=mat[i][j]+3;
        }
    }

    for(i=m+1 ;i<n ;i++){
        for(j=i-m ; j<=i-1 ; j++){
            mat[i][j]=RandomNumber();
            mat[i][i]+=mat[i][j]+4;
        }
    }
}

int min(int x ,int y){
    if(x<y)
    return x ;
    return y ;
}

int max(int x ,int y){
    if(x>y)
    return x ;
    return y ;
}
void affiche_matrice(float **mat,unsigned n){
    for(int i=0;i<n;i++){
        for( int j=0;j<n;j++){
            if(mat[i][j]>9)
            printf("\t%f\t",mat[i][j]);
            else
            printf("\t%f\t",mat[i][j]);
        }

    printf("\n");

    }
    printf("\n");
}
//REMPLISSAGE VECTEUR
void Saisie_V(float *vect,unsigned n){
    unsigned i;
    for(i=0;i<n;i++){
        vect[i]=RandomNumber();
    }
}
void resolution_sup(float **M , float *b, float *x , unsigned n,unsigned m)
{

    int cout;
    for(int i=n-1;i>=0;i--){
        x[i]=b[i];
        cout+=1;
        for(int j=i+1;j<min(n,m+i);j++){
            x[i]-=M[i][j]*x[j];
            cout+=3;
        }
        x[i]=x[i]/M[i][i];
        cout+=2;
    }
    printf("COUT RESOLUTION SUP =%d\n",cout);
}
void gauss(float **mat,unsigned n,unsigned m){
    int cout=0;
    for(int p=0;p<n-1;p++){
        for(int i=p+1;i<n;i++){
            mat[i][p] /= mat[p][p] ;
            cout+=2;
            for( int j=max(p+1,i-m);j<=min(n-1,i+m+1);j++){
                mat[i][j] = mat[i][j] - mat[i][p]*mat[p][j];
                cout+=3;
            }

        }
    }
printf("\nCOUT GAUSS= %d \n",cout);
}
int main(){
    int n= SaisieN();
    int x=SaisieX();
    float *Vec ;
    Vec = (float*)calloc(n,sizeof(float));
    //res Vecteur de resultat
    float res[4]={1,0,55,36};

    float **mat = (float**)malloc(sizeof(float*)*n);

    for(int i=0;i<n;i++){
        mat[i]=(float*)calloc(n,sizeof(float));
    }
    printf("Matrice initial\n");
    Saisie_M(mat,n,x);
    affiche_matrice(mat,n);

    printf("Matrice Final\n");
    gauss(mat,n,x);
    affiche_matrice(mat,n);


    printf("Résultat \n");
    resolution_sup(mat,res,Vec,n,x);
    Affiche_V(Vec,n);
    return 0;
}
