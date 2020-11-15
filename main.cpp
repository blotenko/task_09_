#include <iostream>
using namespace std;

/*
 Описать структуру с именем MARSH, содержащую следующие поля:
 • • •
 .название начального пункта маршрута;
 .название конечного пункта маршрута;
 .номер маршрута.
 2. Написать программу, выполняющую следующие действия:
 .ввод с клавиатуры данных в массив, состоящий из восьми элементов тина MARSH;записи должны быть упорядочены по номерам маршрутов;
 .вывод на экран информации о маршрутах, которые начинаются или кон­ чаются в пункте, название которого введено с клавиатуры;
 .если таких маршрутов нет, выдать на дисплей соответствующее сообще­ние.
 */




struct marsh
 {
  char *begst;
  char *term;
  int numer;
    
};
 
marsh trafic[8];
 



void deletMarsh(int mass1[], char mass2[], char mass3[]){
     for(int i = 1; i <= 4 ; i++){
            mass1[i]=trafic[i].numer;
            mass2[i]= *trafic[i].begst;
            mass3[i]=*trafic[i].term;
      }
    int np=1;
    while(np == 1){
        cout<<endl<<"Удалить какой-то маршрут ? (1 or 0): ";  cin>>np;
        if (np==1){
            int numm;
            cout << "Введите номер маршрута который нужно удалить: ";
            cin>>numm;
            for(int i = 1;i<=4;i++){
                if(i != numm && mass2[i]!=0){
                    cout << "Маршрут номер:  " <<mass1[i]<<endl;
                    cout << "Название начального пункта маршрута: "<<mass2[i]<<endl;
                    cout << "Конечного пункта: " <<mass3[i]<<endl;
                }
                else mass2[i]=0;
                
            }

        }
    }
    for(int i = 1; i <= 4 ; i++){
        trafic[i].numer=mass1[i];
        *trafic[i].begst=mass2[i];
        *trafic[i].term= mass3[i];
     }
}





void showMarsh(int mass1[], char mass2[], char mass3[]){
    int np=1;
    while(np == 1){
        cout<<endl<<"Найти какой-то маршрут ? (1 or 0): ";  cin>>np;
        if(np==1){
      cout << "Введите название пункта: ";
        
      char *naz;
      naz=(char*)malloc(30*sizeof(char));
      cin>>naz;
 
      int k=0;
      for (int i=1; i<=4; i++){
          if ( strcmp(trafic[i].begst, naz) ==0 || strcmp(trafic[i].term, naz) ==0)
          {
              cout << "Маршрут номер:  " <<trafic[i].numer<<endl;
              cout << "Название начального пункта маршрута: "<<trafic[i].begst<<endl;
              cout << "Конечного пункта: " <<trafic[i].term<<endl;
          k++;
          }
          
      }
      if(k==0) cout << "Таких маршрутов нет\n";
    }
    }
    
}

void addMarsh(int mass1[], char mass2[], char mass3[]){
    int nd =1;
    while (nd==1) {
        cout<<endl<<"Добавить новые маршруты ? (1 or 0): ";  cin>>nd;
        if (nd==1){
            for(int i = 1;i<=4;i++){
                if(mass2[i]==0){
                    cout << "Маршрут номер:  " << i <<"\n";
                    mass1[i] = i;
                    cout<< "Название начального пункта маршрута: ";
                    cin>>mass2[i];
                    cout << "Название конечного пункта: ";
                    cin>>mass3[i];
                }
                else{
                    cout << "Маршрут номер:  " <<mass1[i]<<endl;
                    cout << "Название начального пункта маршрута: "<<mass2[i]<<endl;
                    cout << "Конечного пункта: " <<mass3[i]<<endl;
                }
                
            }

        } break;
    }
}
 
int main(){
    setlocale(LC_CTYPE, "ukr");
    for(int i=1; i<=4; i++)
    {
        trafic[i].begst = (char*)malloc(50*sizeof(char));
        trafic[i].term = (char*)malloc(50*sizeof(char));
    }
 
      for(int i = 1; i <= 4 ; i++)
        {
                cout << "Маршрут номер:  " << i <<"\n";
                trafic[i].numer = i;
                cout<< "Название начального пункта маршрута: ";
                gets(trafic[i].begst);
                cout << "Название конечного пункта: ";
                gets(trafic[i].term);
        }
    
    cout << "====================================="<<endl;
    cout<<endl;
    
    
    
    
    int i = 4;
    showMarsh(&trafic[i].numer,trafic[i].begst,trafic[i].term);

    deletMarsh(&trafic[i].numer,trafic[i].begst,trafic[i].term);
    addMarsh(&trafic[i].numer,trafic[i].begst,trafic[i].term);
    
    return 0;
}
