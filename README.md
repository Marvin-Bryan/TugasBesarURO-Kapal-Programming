# Overview Program
Program ini adalah program kapal yang dibuat berdasarkan mekanisme dan spesifikasi dari Tugas Besar Divisi Programming SEKURO 2023, berikut mekanisme dan spesifikasi program kapal:

## Mekanisme Kapal
1. Kapal dapat membaca dan menampilkan posisinya saat ini.
2. Kapal dapat berlayar di empat kuadran pada koordinat kartesian.
3. Kapal dapat bergerak satu satuan ke maju, mundur, ke kanan, atau ke kiri.
3. Kapal tidak dapat menabrak lawan.
4. Kapal tidak dapat keluar dari peta (ukuran peta bebas, disarankan tidak terlalu besar agar kondisi peta saat ini dapat ditampilkan di layar dengan mudah).
5. Kapal memiliki atribut _health_.
6. Kapal dapat menyerang lawan dengan damage yang konstan. Besar _damage_ dibebaskan kepada CAKRU.
7. Meriam kapal memiliki jarak tembak maksimum untuk menyerang lawan. Besar jarak tembak dibebaskan kepada CAKRU.
8. Kapal dapat menghitung jarak dengan lawan.

## Spesifikasi Program
1. Pada awal program, kapal berada pada koordinat (0,0) dan satu armada musuh akan muncul secara acak di koordinat yang tidak sama dengan posisi kapal sekarang.
2. Kapal akan meminta perintah apakah ingin menembak, bergerak, atau diam di tempat.
3. Jika kapal musuh berada di luar jarak tembak kapal maksimum, keluarkan pesan error.
4. Program akan berhenti ketika *health* kapal kurang dari atau sama dengan 0.
5. Saat program berhenti, keluarkan jumlah kapal musuh yang berhasil dikalahkan.
6. Kapal musuh juga memiliki atribut *health*, *damage*, dan jarak serangan maksimum.
7. Nilai atribut dari kapal dan kapal musuh dibebaskan kepada CAKRU.

## Cara Menjalankan
Saat dijalankan, program akan menampilkan peta sederhana berukuran 21 x 21 yang berisi informasi letak awal kapal di koordinat (0, 0) dan letak 5 kapal musuh secara acak, posisi koordinat kapal, dan perintah awal kapal. 

Program akan meminta user untuk meng-*input* perintah yang akan dilakukan kapal. Berikut perintah awal yang dapat dimasukkan:
1. *Move* (gerak), setelah memilih perintah ini, program akan meminta arah gerak kapal, 'u' up, 'd' down, 'r' right, 'l' left.
2. *Attack* (serang), kapal akan menyerang kapal musuh sekitar dengan jarak serangan 5.
3. *Stay* (tetap), kapal akan berdiam diri dan tidak berbuat apa-apa.

Setelah itu, program akan berjalan terus hingga program akan berhenti ketika 5 kapal musuh yang ada di peta telah **dikalahkan** semua atau **_health_** kapal kurang dari atau sama dengan 0.

>Bonus : kapal yang telah dikalahkan akan menjadi **"kapal hantu"** yang terkadang akan tetap menyerang jika kapal kita ada di jarak serang **"kapal hantu"** tersebut

## Link GitHub :
```
https://github.com/Marvin-Bryan/TugasBesarURO-Kapal-Programming/edit/bot/README.md
```

## Peran Anggota
- Marvin Bryan Juanethan - 16522096 = algoritma cek koordinat dan fungsi penampilan peta
- Mahardhika Putra Adipratama - 16522159 = algortima ditembak, gerak dan arahnya, serangan musuh, tracking jumlah Kapal yang dihancurkan, dan spawning musuh
- Ammar Naufal - 19622047 = algoritma gerak, membantu proses debugging, membuat overview dan dokumentasi
- Ahmad Hasan Albana - 19622116 = algortima menembak, tampilan map, tracking pergerakan kapal, dan batas gerak
