Nomor 5

SELECT golongan_darah, jenis_kelamin, count(mahasiswa.nama), (sum(nilai*sks)/sum(sks))
FROM mahasiswa JOIN mengambil ON mahasiswa.nim=mengambil.nim JOIN kelas ON mengambil.id_kelas=kelas.id_kelas JOIN kuliah ON kelas.kode_kuliah=kuliah.kode_kuliah
GROUP BY golongan_darah, jenis_kelamin
ORDER BY jenis_kelamin ASC, golongan_darah ASC;

Nomor 4
SELECT kuliah.kode_kuliah, kuliah.nama, count(DISTINCT mengambil.nim),  count(DISTINCT nomor_kelas), avg(mengambil.nilai) #, count(mengambil.nilai=4), count(mengambil.nilai=3.5), count(mengambil.nilai=3), count(mengambil.nilai as =2.5), count(mengambil.nilai =2), count(mengambil.nilai=1), count(mengambil.nilai=0)
FROM mahasiswa JOIN mengambil ON mahasiswa.nim=mengambil.nim JOIN kelas ON mengambil.id_kelas=kelas.id_kelas JOIN kuliah ON kelas.kode_kuliah=kuliah.kode_kuliah
#WHERE A=4 and AB=3.5 and B=3 and BC=2.5 and C=2 and D=1 and E=0
GROUP BY kuliah.kode_kuliah;