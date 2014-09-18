#include "Evaluador.h"

void evaluar()
{
    int infinito = 9999;
    int grafo[5][5];

    for(int col=0;col<5;col++)
        for(int fila=0;fila<5;fila++)
            if(fila==col)
                grafo[fila][col]=0;
            else
                grafo[fila][col]=infinito;

    grafo[0][1]=2;
    grafo[0][2]=6;
    grafo[0][3]=7;

    grafo[1][3]=3;
    grafo[1][4]=6;

    grafo[2][4]=1;

    grafo[3][4]=5;


    double nota = 0;

    cout<<"Ejercicio existeCamino():\t\t";
    double nota_existe = 0;
    if(!existeCamino(grafo,4,1) && existeCamino(grafo,1,4) && !existeCamino(grafo,3,1) && existeCamino(grafo,2,4))
    {
        nota_existe+=1;
    }
    if(existeCamino(grafo,0,4) && !existeCamino(grafo,4,1) && existeCamino(grafo,1,4) && !existeCamino(grafo,3,1) && existeCamino(grafo,2,4))
    {
        nota_existe+=2.5;

    nota+=nota_existe;
    if(nota==3,5)
    {
        cout<<"Correcto"<<endl;
    }
    }else if(nota_existe>0)
    {
        cout<<"Casi"<<endl;
    }else
    {
        cout<<"Incorrecto"<<endl;
    }

    set<int> alumno = obtenerAdjacentes(grafo,0, 0);
    set<int> respuesta;
    respuesta.insert(0);


    set<int> alumno2 = obtenerAdjacentes(grafo,0, 1);
    set<int> respuesta2;
    respuesta2.insert(0);
    respuesta2.insert(1);
    respuesta2.insert(2);
    respuesta2.insert(3);


    set<int> alumno3 = obtenerAdjacentes(grafo,0, 2);
    set<int> respuesta3;
    respuesta3.insert(0);
    respuesta3.insert(1);
    respuesta3.insert(2);
    respuesta3.insert(3);
    respuesta3.insert(4);

    set<int> alumno4 = obtenerAdjacentes(grafo,1, 0);
    set<int> respuesta4;
    respuesta4.insert(1);

    set<int> alumno5 = obtenerAdjacentes(grafo,1, 1);
    set<int> respuesta5;
    respuesta5.insert(1);
    respuesta5.insert(3);
    respuesta5.insert(4);

    set<int> alumno6 = obtenerAdjacentes(grafo,1, 2);
    set<int> respuesta6;
    respuesta6.insert(1);
    respuesta6.insert(3);
    respuesta6.insert(4);

    cout<<"Ejercicio obtenerAdjacentes():\t\t";
    double nota_adj=0;
    if((alumno==respuesta) && (alumno4==respuesta4))
    {
        nota_adj+=1;
    }
    if((alumno2==respuesta2) && (alumno5==respuesta5))
    {
        nota_adj+=1;
    }
    if((alumno3==respuesta3) && (alumno6==respuesta6))
    {
        nota_adj+=1.5;
    }

    nota+=nota_adj;
    if(nota_adj==3.5)
    {
        cout<<"Correcto"<<endl;
    }else if(nota_adj>0)
    {
        cout<<"Casi"<<endl;
    }
    else
    {
        cout<<"Incorrecto"<<endl;
    }

    cout<<endl<<"Nota: "<<nota<<"/7"<<endl;
}
