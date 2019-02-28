#include "Matriks.h"

// ctor inisialisasi n_brs dan n_kol dengan ctor initialization list, N=M=defsize
// Seluruh elemen matriks diinisialisasi dengan nilai 0
Matriks::Matriks() : num_brs(DEFSIZE), num_kol(DEFSIZE){
    b = new int*[num_brs];
    for (int i = 0; i < num_brs; i++){
        b[i] = new int[num_kol];
        for (int j = 0; j<num_kol; j++){
            b[i][j] = 0;
        }
    }
}

// ctor dengan param n (banyaknya baris) dan m (banyaknya kolom)
// Seluruh elemen matriks diinisialisasi dengan nilai 0
Matriks::Matriks(int n, int m) : num_brs(n), num_kol(m){
    b = new int*[num_brs];
    for (int i = 0; i < num_brs; i++){
        b[i] = new int[num_kol];
        for (int j = 0; j<num_kol; j++){
            b[i][j] = 0;
        }
    }
}

// cctor
Matriks::Matriks(const Matriks &m) : num_brs(m.num_brs), num_kol(m.num_kol){
    b = new int*[num_brs];
    for (int i = 0; i < num_brs; i++){
        b[i] = new int[num_kol];
        for (int j = 0; j<num_kol; j++){
            b[i][j] = m.b[i][j];
        }
    }
}

// dtor
Matriks::~Matriks(){
    for (int i = 0; i < num_brs; i++){
        delete[] b[i];
    }
    delete[] b;
}

// operator= menjamin tidak bitwise copy.
// dan dapat melakukan assignment m1=m2; prekondisi: ukuran m1=ukuran m2
Matriks& Matriks::operator=(Matriks &m){
    for (int i = 0; i < num_brs; i++){
        for (int j = 0; j<num_kol; j++){
            b[i][j] = m.b[i][j];
        }
    }
    return *this;
}

// test apakah ukuran sama: true jika m1.num_brs== m2.num_brs && m1.num_kol== m2.num_kol
bool IsEqSize(Matriks m1, Matriks m2){
    return (m1.num_brs == m2.num_brs) && (m1.num_kol == m2.num_kol);
}

// operator+ penjumlahan nilai b dari kedua matriks yg posisinya sama
// Mhasil(i,j) = M1 (i,j) + M2(i,j)
// Proses : jika ukuran m2 tak sama dengan current object,
// yang tak beririsan tidak dijumlahkan, hanya dicopy
// hasilnya adalah matriks yang lebih besar
// ditulis sebagai function member
Matriks Matriks::operator+(Matriks m2){
    int max_brs = num_brs > m2.num_brs ? num_brs : m2.num_brs;
    int max_kol = num_kol > m2.num_kol ? num_kol : m2.num_kol;
    Matriks newM(max_brs, max_kol);
    for (int i = 0; i < m2.num_brs; i++){
        for (int j = 0; j < m2.num_kol; j++){
            newM.b[i][j] += m2.b[i][j];
        }
    }
    for (int i = 0; i < num_brs; i++){
        for (int j = 0; j < num_kol; j++){
            newM.b[i][j] += b[i][j];
        }
    }
    return newM;
}

// operator- pengurangan nilai b dari kedua matriks yg posisinya sama
// Mhasil(i,j) = M1 (i,j) - M2(i,j)
// Proses : jika ukuran m2 tak sama dengan current object,
// yang tak beririsan tidak dijumlahkan, hanya dicopy
// hasilnya adalah matriks yang lebih besar
// ditulis sebagai friend function
Matriks operator-(const Matriks &m1, const Matriks &m2){
    int max_brs = m1.num_brs > m2.num_brs ? m1.num_brs : m2.num_brs;
    int max_kol = m1.num_kol > m2.num_kol ? m1.num_kol : m2.num_kol;
    Matriks newM(max_brs, max_kol);
    for (int i = 0; i < m2.num_brs; i++){
        for (int j = 0; j < m2.num_kol; j++){
            if (i < m1.num_brs && j < m1.num_kol){
                newM.b[i][j] -= m2.b[i][j];
            }
            else{
                newM.b[i][j] += m2.b[i][j];
            }
        }
    }
    for (int i = 0; i < m1.num_brs; i++){
        for (int j = 0; j < m1.num_kol; j++){
            newM.b[i][j] += m1.b[i][j];
        }
    }
    return newM;
}

// operator* perkalian dengan sebuah bilangan konstanta
// ditulis sebagai function member
Matriks Matriks::operator*(const int n){
    for (int i = 0; i < num_brs; i++){
        for (int j = 0; j < num_kol; j++){
            b[i][j] *= n;
        }
    }
    return *this;
}

// operator* perkalian dengan sebuah bilangan konstanta
// diimplementasikan untuk memenuhi sifat komutatif
// ditulis sebagai frined function
Matriks operator*(const int n, const Matriks m2){
    Matriks newM(m2.num_brs, m2.num_kol);
    for (int i = 0; i < newM.num_brs; i++){
        for (int j = 0; j < newM.num_kol; j++){
            newM.b[i][j] = n*m2.b[i][j];
        }
    }
    return newM;
}

// isikan nilai v di posisi data[i,j], i dan j terdefinisi
void Matriks::SetData(int i, int j, int v){
    b[i][j] = v;
}

// ambil elemen v di posisi data[i,j], i dan j terdefinisi
int Matriks::GetData(int i, int j) const{
    return b[i][j];
}

// Mengembalikan num_brs
int Matriks::GetBrs() const{
    return num_brs;
}
// Mengembalikan num_kol
int Matriks::GetKol() const{
    return num_kol;
}
// Mengecek apakah num_brs sama dengan num_kol
bool Matriks::IsSimetri() const{
    if (num_brs == num_kol){
        bool simetri = true;
        for (int i = 0; i < num_brs; i++){
            for (int j = i+1; j < num_kol; j++){
                if (b[i][j] != b[i][j]){
                    simetri = false;
                }
            }
        }
        return simetri;
    }
    else{
        return false;
    }
}