SELECT a.id_kelas, a.nomor_kelas, a.kode_kuliah, b.nama, c.nama
FROM kelas as a, kuliah as b, dosen as c
WHERE a.kode_kuliah=b.kode_kuliah and a.nip_dosen=c.nip
