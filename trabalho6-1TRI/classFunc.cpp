#include <iostream>
#include <vector>
#include "classFunc.hpp"

using namespace std;

void adicionarDias(int dtaInicial[3], int dias, int (*dtaFinal)[3]){
    int dia = dtaInicial[0] ;
    int mes = dtaInicial[1];
    int ano = dtaInicial[2];

    for(int i = 0; i < dias; i++){
        dia++;
        if(dia > 31 and (mes == 1 or mes == 3 or mes == 5 or mes == 7 or mes == 8 or mes == 10)){
            dia = 1;
            mes++;
        }else if(dia > 30 and (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
            dia = 1;
            mes++;
        }else if(mes == 2){
            if(ano % 4 == 0){
                if(dia > 29){
                    dia = 1;
                    mes++;
                }
            }else{
                if(dia > 28){
                    dia = 1;
                    mes++;
                }
            }
        }else if(dia > 31 and mes == 12){
            dia = 1;
            mes = 1;
            ano++;
        }
    }

    *dtaFinal[0] = dia;
    *dtaFinal[1] = mes;
    *dtaFinal[2] = ano;
}

int diasAte(int dtaInicial[3], int dtaFinal[3]){
    int diaInicial = dtaInicial[0];
    int mesInicial = dtaInicial[1];
    int anoInicial = dtaInicial[2];
    int diaFinal = dtaFinal[0];
    int mesFinal = dtaFinal[1];
    int anoFinal = dtaFinal[2];
    int dias = 0;

    while(diaInicial or diaFinal or mesInicial != mesFinal or anoInicial != anoFinal){
        diaInicial++;
        dias++;
        if(diaInicial > 31 and (mesInicial == 1 or mesInicial == 3 or mesInicial == 5 or mesInicial == 7 or mesInicial == 8 or mesInicial == 10)){
            diaInicial = 1;
            mesInicial++;
        }else if(diaInicial > 30 and (mesInicial == 4 || mesInicial == 6 || mesInicial == 9 || mesInicial == 11)){
            diaInicial = 1;
            mesInicial++;
        }else if(mesInicial == 2){
            if(anoInicial % 4 == 0){
                if(diaInicial > 29){
                    diaInicial = 1;
                    mesInicial++;
                }
            }else{
                if(diaInicial > 28){
                    diaInicial = 1;
                    mesInicial++;
                }
            }
        }else if(diaInicial > 31 and mesInicial == 12){
            diaInicial = 1;
            mesInicial = 1;
            anoInicial++;
        }
    }

    return dias;

}