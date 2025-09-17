# TP1DPBO2425C1

# Janji
Saya Daffa Dhiyaa Candra dengan NIM 2404286 mengerjakan 
TP 1 dalam mata kuliah Desain dan Pemrograman
Berorientasi Objek untuk keberkahanNya maka saya tidak 
melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.

# Desain Program
Program saya terdiri dari 7 atribut
1. ID
2. Name
3. Brand
4. Color
5. Price
6. Warranty
7. Image (PHP only)

# Alur Program
Untuk bahasa C++, Java dan Python, dalam program ada 6 menu yang bisa dipilih oleh user.
[1]. Add Data Laptop
[2]. Update Data Laptop
[3]. Hapus Data Laptop
[4]. Cari Data Laptop
[5]. Tampilkan Semua Laptop
[6]. Keluar Dari Program

1. Untuk menambahkan data produk, user harus memasukkan 6 atribut, id, name, brand, color, price, dan warranty. Kemudian jika ID yang dimasukkan sudah ada, maka akan muncul pesan error "ID already exists. Please enter a different ID". Jika ID yang dimasukkan bukan berupa angka maka akan muncul pesan error "ID must be a number". Kemudian untuk atribut price, jika user memasukkan bilangan negative atau memasukkan string, akan muncul pesan error "Please enter a valid price.". Begitu pula untuk atribut warranty akan menampilkan pesan error "Please enter a valid warranty period." jika inputan negative atau string. Di dalam bahasa PHP ada tambahan atribut image untuk ditampilkan di daftar laptop.

2. Untuk mengubah data Laptop, user harus memasukkan ID terlebih dahulu kemudian di cek apakah ID sudah ada apa belum. Jika belum, maka akan memunculkan pesan error "Laptop not found". Sama seperti input, jika ID yang dimasukkan bukan berupa angka maka akan muncul pesan error "ID must be a number". Begitu pula dengan atribut price dan warranty. Setelah input selesai maka akan ditampilkan data Laptop yang baru.

3. Untuk menghapus data Laptop, user harus memasukkan ID terlebih dahulu kemudian di cek apakah ID sudah ada apa belum. Jika belum, maka akan memunculkan pesan error "Laptop not found". Sama seperti input, jika ID yang dimasukkan bukan berupa angka maka akan muncul pesan error "ID must be a number". Jika Laptop yang ingin dihapus ada, nanti akan ditampilkan data laptop yang ingin dihapus. Kemudian kode akan meminta inputan validasi berupa 'Y' atau 'N'. Jika inputan 'Y', data Laptop akan dihapus dan menampilkan pesan "Laptop deleted.". Jika inputan 'N', akan menampilkan pesan "Laptop not deleted.".

4. Untuk mencari data Laptop, user harus memasukkan ID terlebih dahulu kemudian di cek apakah ID sudah ada apa belum. Jika belum, maka akan memunculkan pesan error "Laptop not found". Jika ada, maka kode akan menampilkan data Laptop sesuai dengan ID yang ingin dicari.

5. Jika user memilih opsi 5, maka kode akan menampilkan seluruh data laptop yang ada.

6. Jika user memilih opsi 6, maka kode akan selesai dan menampilkan pesan "Exiting program.".

# Dokumentasi

## Output
### Menu
![Menu](Dokumentasi/Cpp%20Menu.png)
### Input
![Input](Dokumentasi/Cpp%20Input.png)
### Update
![Update](Dokumentasi/Cpp%20Update.png)
### Delete
![Delete](Dokumentasi/Cpp%20Delete.png)
### Search
![Search](Dokumentasi/Cpp%20Search.png)
### Display
![Display All](Dokumentasi/Cpp%20Display%20All.png)
### Exit
![Exit](Dokumentasi/Cpp%20Exit.png)

### Error Handling
Jika ID tidak valid  
![Error 1](Dokumentasi/Cpp%20Error%201.png)  

Jika menginput selain angka di bagian harga  
![Error 2](Dokumentasi/Cpp%20Error%202.png)  

Jika menginput selain angka di bagian garansi  
![Error 3](Dokumentasi/Cpp%20Error%203.png)  

Jika ID tidak ditemukan saat mengubah, menghapus, atau mencari  
![Error 4](Dokumentasi/Cpp%20Error%204.png)  


## PHP
Tampilan Utama
![PHP Menu](Dokumentasi/PHP%20Menu.png)
Tampilan Input
![PHP Input](Dokumentasi/PHP%20Input.png)
Tampilan Cari
![PHP Search](Dokumentasi/PHP%20Search.png)
Tampilan Edit
![PHP Edit](Dokumentasi/PHP%20edit.png)
Tombol Hapus
![PHP Delete](Dokumentasi/PHP%20Delete.png)
