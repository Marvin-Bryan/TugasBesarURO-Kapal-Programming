### Overview Program
 
Program ini adalah program kapal yg dibuat berdasarkan mekanisme dan spesifikasi dari Tugas Besar divisi programming yg berada pada Teams SEKURO

berikut Mekanisme dan Spesifikasi nya:
#### Mekanisme Kapal
Kapal dapat membaca dan menampilkan posisinya saat ini
Kapal dapat berlayar di empat kuadran pada koordinat kartesian
Kapal dapat bergerak satu satuan ke maju, mundur, ke kanan, atau ke kiri.
Kapal tidak dapat menabrak lawan.
Kapal tidak dapat keluar dari peta (ukuran peta bebas, disarankan tidak terlalu besar agar kondisi peta saat ini dapat ditampilkan di layar dengan mudah)
Kapal memiliki atribut health
Kapal dapat menyerang lawan dengan damage yang konstan. Besar damage dibebaskan kepada CAKRU.
Meriam kapal memiliki jarak tembak maksimum untuk menyerang lawan. Besar jarak tembah dibebaskan kepada CAKRU.
Kapal dapat menghitung jarak dengan lawan.

#### Spesifikasi Program
Pada awal program, kapal berada pada koordinat (0,0) dan satu armada musuh akan muncul secara acak di koordinat yang tidak sama dengan posisi kapal sekarang.
Kapal akan meminta perintah apakah ingin menembak, bergerak, atau diam di tempat.
Jika kapal musuh berada di luar jarak tembak kapal maksimum, keluarkan pesan error.
Program akan berhenti ketika health kapal kurang dari atau sama dengan 0.
Saat program berhenti, keluarkan jumlah kapal musuh yang berhasil dikalahkan.
Kapal musuh juga memiliki atribut health, damage, dan jarak serangan maksimum.
Nilai atribut dari kapal dan kapal musuh dibebaskan kepada CAKRU.

### Cara Menjalankan

Ketika di run, program ini akan segera meminta user akan input yg menentukan tindakan apa yang user ingin terapkan pada kapal, untuk menjalankan kapal milik user cukup simple dan jelas, hanya membutuhkan user untuk mengikuti petunjuk dari program.

Ketika program dijalankan untuk pertama kali nya, program akan meng-spawn kapal milik user dan 5 kapal musuh yg diletakkan secara random, musuh dan kapal user akan bergerak/melakukan aksi setiap program menerima input dari user. Jadi usahakan gerakan anda sebagai user seefisien mungkin agar dapat meraih kemenangan.

### Link GitHub
https://github.com/Marvin-Bryan/TugasBesarURO-Kapal-Programming/edit/bot/README.md

### Peran Anggota

Marvin Bryan Juanethan	16522096 = Algortima Cek Koordinat dan Fungsi penampilan Peta
Mahardhika Putra Adipratama	16522159 = Algortima Ditembak, Gerak dan Arahnya, Serangan Musuh, Tracking jumlah Kapal yang dihancurkan, dan Spawning musuh
Ammar Naufal	19622047 = Algoritma Gerak
Ahmad Hasan Albana	19622116 = Algortima Menembak, Map, dan Batas Gerak
