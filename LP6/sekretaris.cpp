/*
Nama : Muhammad Rizki Fonna
NIM  : 13516001

*/

#include <iostream>
#include "sekretaris.h"

using namespace std;
/*
	Membuat objek Sekretaris dengan nilai kertas dan tinta
	default. Besar energi awal adalah ENERGI_MAX
*/
Sekretaris :: Sekretaris(){
		energi = ENERGI_MAX;
		tinta = TINTA_DEFAULT;
		kertas = KERTAS_DEFAULT;
		memoLength = 0;
		memo = new Memo[256];
	}
/*
	Membuat objek Sekretaris dengan nilai kertas dan tinta
	sesuai yang diberikan. Besar energi awal adalah ENERGI_MAX
*/
Sekretaris :: Sekretaris(int kertas, int tinta){
		energi = ENERGI_MAX;
		this->tinta = tinta;
		this->kertas = kertas;
		memoLength = 0;
		memo = new Memo[256];
	}
/*
	Dealokasi variabel-variabel yang perlu didealokasi.
	Jika tidak perlu, hapus metode ini.
*/
Sekretaris :: ~Sekretaris(){
		delete[] memo;
	}

/*
	Membuat memo dengan isi sesuai yang diberikan. Metode ini
	menggunakan metode pakaiKertas, pakaiTinta, dan pakaiEnergi.
	Untuk membuat 1 memo akan menghabiskan 1 kertas, 1 energi,
	dan tinta sebanyak jumlah karakter pesan.

	Ada beberapa penyebab memo gagal dibuat, yaitu:
	- Jika kertas habis, akan mengeluarkan pesan dari exception,
	  ditambah dengan ", segera isi kertas"
	- Jika tinta kurang, akan mengeluarkan pesan dari exception,
	  ditambah dengan ", segera isi tinta"
	- Jika energi habis, akan mengeluarkan pesan dari exception,
	  ditambah dengan ", segera istirahat"
	- Jika kertas habis, akan mengeluarkan pesan dari exception,
	  ditambah dengan ", segera isi kertas"

	Jika memo gagal dibuat, maka tinta, kertas, dan energi tidak
	berkurang. Gunakan metode batalPakaiKertas, batalPakaiTinta,
	dan batalPakaiEnergi.

	Jika berhasil, maka memo akan dimasukkan ke daftar memo serta
	menampilkan pesan "Memo [<nomor_memo>] untuk <untuk> berhasil
	dibuat"

	Keterangan:
	<...> -> ganti dengan nilai yang sesuai.
*/
void Sekretaris :: buatMemo(string pesan, string untuk)
	{
		 try
			{
				pakaiKertas();
					try
						{
							pakaiTinta(pesan.length());
								try {
									pakaiEnergi();
										try
											{
												Memo new_mem = Memo(pesan,untuk);
												memo[memoLength] = new_mem;
												memoLength = memoLength + 1;
												cout << "Memo [" << memoLength << "] untuk " << untuk << " berhasil dibuat" << endl;
											}
										catch ( PesanKepanjanganException& e)
											{
												cout << e.what() << ", perpendek pesannya" << endl;
												batalPakaiEnergi();
												batalPakaiTinta(pesan.length());
												batalPakaiKertas();
											}
									}
								catch (EnergiHabisException& e)
									{
										cout << e.what() << ", segera istirahat" << endl;
										batalPakaiTinta(pesan.length());
										batalPakaiKertas();
									}
						}
					catch( TintaKurangException& e)
						{
							cout << e.what() << ", segera isi tinta" << endl;
							batalPakaiKertas();
						}
				
			}
		catch ( KertasHabisException& e )
			{
				cout << e.what() << ", segera isi kertas" << endl;
			}
		
	}
	
/*
	Menggunakan 1 kertas.

	Jika kertas tidak cukup, maka metode ini akan melemparkan
	KertasHabisException.
*/
void Sekretaris :: pakaiKertas()
	{
		if (kertas < 1 )
			{
				throw KertasHabisException();
			}
		else
			{
				kertas = kertas - 1;
			}
	}
/*
	Menggunakan tinta sebanyak num.

	Jika tinta tidak cukup, maka metode ini akan melemparkan
	TintaKurangException.
*/
void Sekretaris :: pakaiTinta(int num)
	{
		if (tinta < num)
			{
				throw TintaKurangException();
			}
		else
			{
				tinta = tinta - num;
			}
	}
/*
	Menggunakan 1 energi.

	Jika energi tidak cukup, maka metode ini akan melemparkan
	EnergiHabisException.
*/
void Sekretaris :: pakaiEnergi()
	{
		if ( energi < 1 )
			{
				throw EnergiHabisException();
			}
		else
			{
				energi = energi - 1;
			}
	}
/*
	Membatalkan penggunaan 1 kertas.
*/
void Sekretaris :: batalPakaiKertas()
	{
		kertas = kertas + 1;
	}
/*
	Membatalkan penggunaan tinta sebanyak num.
*/
void Sekretaris :: batalPakaiTinta(int num)
	{
		tinta = tinta + num;
	}
/*
	Membatalkan penggunaan 1 energi.
*/
void Sekretaris :: batalPakaiEnergi()
	{
		energi = energi + 1;
	}
/*
	Menambahkan jumlah tinta sebanyak num.
*/
void Sekretaris :: isiTinta(int num)
	{
		tinta = tinta + num;
	}
/*
	Menambahkan jumlah kertas sebanyak num.
*/
void Sekretaris :: isiKertas(int num)
	{
		kertas = kertas + num;
	}
/*
	Istirahat mengembalikan energi menjadi maksimum.
*/
void Sekretaris :: istirahat()
	{
		energi = ENERGI_MAX;
	}
/*
	Menampilkan status dari sekretaris. Berikut adalah format tampilan:
	<...> -> tampilkan nilai yang sesuai
	(...) -> komentar, tidak termasuk output

	--------------
	Status
	  Energi : <jumlah_energi>
	  Tinta : <jumlah_tinta>
	  Kertas : <jumlah_kertas>
	  Memo : <jumlah_memo>
		(untuk setiap memo ke-i, mulai dari 1)
		Memo [<i>]
		  Pesan : <pesan_memo_i>
		  Untuk : <untuk_memo_i>
	--------------

	(Output tidak termasuk ---------- di awal dan akhir)
*/
void Sekretaris :: printStatus()
	{
		cout << "Status" << endl;
		cout << "  Energi : " << energi << endl;
		cout << "  Tinta : " << tinta << endl;
		cout << "  Kertas : " << kertas << endl;
		cout << "  Memo : " << memoLength << endl;
		
		for (int i = 0 ; i < memoLength ; i++ )
			{
				printf("    Memo [%d]\n",i+1);
				cout << "      Pesan : " << memo[i].getPesan() << endl;
				cout << "      Untuk : " << memo[i].getUntuk() << endl; 
			}
	}
