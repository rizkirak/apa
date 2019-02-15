SELECT a.nim, a.nama, count(id_kelas)
FROM mahasiswa as a, mengambil as b
WHERE a.nim=b.nim
GROUP BY a.nim;
