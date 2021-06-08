#include<stdio.h>
int in(int lista[],int numero,int longitud){
    for (int i = 0; i < longitud; i++)
    {
        if (numero==lista[i])
        {
            return 1;
        }
    }
    return 0;
}
void main(){
    int n,s,repetidor=0,a;
    int ramaIzq[5];
    int ramaDer[5];
    int num;
    //ingreso array izq
    printf("ingreso rama izquierda: \n");
    for (int i = 0; i < 5; ++i)
    {   num=0;
        scanf("%d",&num);
        ramaIzq[i]=num;
        printf("----\n");
    }

    //ingreso array der
    printf("ingreso rama derecha: \n");
    for (int i = 0; i < 5; ++i)
    {   num=0;
        scanf("%d",&num);
        ramaDer[i]=num;
        printf("----\n");
    }
    //buscar moda ramaIzq
    for(int i=0;i<5;i++){
        s=0;
        for(int j=0;j<5;j++){
            if(ramaIzq[i]==ramaIzq[j] && i!=j){
                s=s+1;
            }               
        }
        if(s>=repetidor){
        repetidor=s;//guardamos el mayor por el momento
        a=i;    
        }
    }
    int repIzq;
    repIzq=ramaIzq[a];
    //m tiene las repeticiones pero no se esta contando a si misma por eso m+1
    printf("la moda  izq es: %d y tiene %d repeticiones\n\n",ramaIzq[a],repetidor+1);
    //verificar existencia en el array derecho
    //debug
    printf("-> %d\n",repIzq);
    printf("-> %d\n",in(ramaDer,repIzq,5));
    //debug
    if (in(ramaDer,repIzq,5)==1){
        for (int i = 0; i < 5; ++i){
            if(repIzq==ramaDer[i]){
                repetidor=repetidor+1;
            }
        }
        printf("en el brazo der se repiten más %d!\n",ramaIzq[a]);
        printf("la moda  izq es: %d y tiene %d repeticiones en total con ambos brazos\n\n",ramaIzq[a],repetidor+1);
    }

    //borrar datos
    
    int m=0;
    s=0;
    int b=0;
    //buscar moda ramaDer
    for(int i=0;i<5;i++){
        s=0;
        for(int j=0;j<5;j++){
            if(ramaDer[i]==ramaDer[j] && i!=j){
                s=s+1;
            }               
        }
        if(s>=m){
        m=s;//guardamos el mayor por el momento
        b=i;    
        }
    }
    int repDer;
    repDer=ramaDer[b];
    printf("la moda der es: %d y tiene %d repeticiones\n",ramaDer[b],m+1);
    //verificar existencia en el array izq
    if (in(ramaIzq,repDer,5)==1){
        for (int i = 0; i < 5; ++i){
            if(repDer==ramaIzq[i]){
                m=m+1;
            }
        }
        printf("en el brazo izq se repiten más %d!\n",ramaDer[b]);
        printf("la moda  izq es: %d y tiene %d repeticiones en total con ambos brazos\n\n",ramaDer[b],m+1);
    }
    if (repetidor>m)
    {
        printf("El numero que más se repite es: %d",ramaIzq[a]);
    }
    else{
        printf("El numero que más se repite es: %d",ramaDer[b]);
    }
}