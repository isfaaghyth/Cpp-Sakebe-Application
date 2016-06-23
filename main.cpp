#include <iostream>
#include <time.h>
#include <string>
#include <cstdlib>
#include <Windows.h>
#include <fstream>
using namespace std;
 
int main() {
        srand (time(NULL));
        int jml_kelompok;
        //lakukan penginputan
        int jml_nama;
        cout<<"Berapa jumlah siswa di kelas: ";cin>>jml_nama;
        string daftarnama[jml_nama];
        cout<<"Silahkan input nama-nama kelompok: \n";
        for (int i=0;i<jml_nama;i++) {
                cin>>daftarnama[i];
        }
        cout<<"Silahkan input jumlah kelompok: ";
        cin>>jml_kelompok;
        int perkelompok = jml_nama/jml_kelompok;
        string kelompok[perkelompok];
        int indeks;
        ofstream save;
        save.open("Sakebe - Pembagi Kelompok.txt");
        save<<"Sakebe - Aplikasi pembagi kelompok didalam kelas."<<endl<<endl;
        for (int no_kelompok=0;no_kelompok<jml_kelompok;no_kelompok++) {
                cout<<"Kelompok : "<<no_kelompok+1;
                save<<"Kelompok : "<<no_kelompok+1<<endl;
                for (int i = 0;i<perkelompok;i++) {
                        indeks = rand()%jml_nama;
                        kelompok[i] = daftarnama[indeks];
                        for (int j=indeks+1;j<jml_nama;j++) {
                                daftarnama[j-1]=daftarnama[j];
                        }
                        jml_nama--;
                }
                for (int i=0;i<perkelompok;i++) {
                        cout<<"\n"+kelompok[i];
                        save<<kelompok[i]<<endl;
                }
                cout<<"\n";
        }
        save.close();
}
