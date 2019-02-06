/*
 * Nama     : Dery Rahman A
 * NIM      : 13515097
 * Topik    : Praktikum Sekawan dan Inheritance
 * Tanggal  : 10-02-2017
 */

#ifndef GENMATRIKS_H
#define GENMATRIKS_H

#include <ostream>
using namespace std;

template <class atype>
class GenMatriks {
// kelas matriks yang generik
public:
// ctor tanpa parameter
// create sebuah matriks berukuran defaultbaris x defaultkol
  GenMatriks() : nBrs(defsize), nKol(defsize){
    this->data=new atype*[this->nBrs];
    for(int i=0;i<this->nBrs;i++)
      this->data[i]=new atype[this->nKol];
  }
// ctor dengan parameter
// create sebuah matriks berukuran defaultbaris x defaultkol
  GenMatriks(int nb, int nk) : nBrs(nb), nKol(nk){
    this->data=new atype*[this->nBrs];
    for(int i=0;i<this->nBrs;i++)
      this->data[i]=new atype[this->nKol];
  }
// cctor menjamin terbentuk matriks dengan data dicopy GenMatriks
  GenMatriks(const GenMatriks<atype>& gm) : nBrs(gm.nBrs), nKol(gm.nKol){
    this->data=new atype*[this->nBrs];
    for(int i=0;i<this->nBrs;i++){
      this->data[i]=new atype[this->nKol];
      for(int j=0;j<this->nKol;j++)
        this->data[i][j]=gm.data[i][j];
    } 
  }
// operator= yang menjamin data dicopy, bukan bitwise copy
  GenMatriks<atype>& operator=(const GenMatriks<atype>& gm){
      for(int i=0;i<gm.nBrs;i++){
          for(int j=0;j<gm.nKol;j++){
              this->data[i][j]=gm.data[i][j];
          }
      }
      return *this;
  }
// dtor
// membebaskan kembali memori yang dipakai data
  ~GenMatriks(){
      for(int i=0;i<this->nBrs;i++)
          delete this->data[i];
      delete this->data;
  }
// isi elemen v di posisi data[i,j], i dan j terdefinisi
  void setData (int i, int j, atype v){
    this->data[i][j]=v;
  }
// ambil elemen v di posisi data[i,j], i dan j terdefinisi
  atype getData (int i, int j){
    return this->data[i][j];
  }
// getter
  int GetNBrs(){
    return this->nBrs;
  }
  int GetNKol(){
    return this->nKol;
  }
// io stream. Implementasi fungsi dibuat di sini.
  template <class T>
  friend ostream& operator<< (ostream &os, const GenMatriks<T>& gm);

private :
  const int defsize=100;
  const int nBrs; // banyaknya baris efektif
  const int nKol; // banyaknya kolom efektif
  atype ** data;
};

template <class T>
ostream& operator<< (ostream &os, const GenMatriks<T>& gm){ 
    for(int i=0;i<gm.nBrs;i++){
        for(int j=0;j<gm.nKol-1;j++){
            os << gm.data[i][j] << " ";
        }
        os << gm.data[i][gm.nKol-1] << endl;
    }
    return os;
  }
#endif
