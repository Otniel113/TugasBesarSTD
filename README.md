# TugasBesarSTD
Tugas Besar untuk Mata Kuliah Struktur Data yang dikerjakan secara kelompok 2 orang bersama Gilang Muhammad Rizky

## Deskripsi Singkat
Program ini menggunakan implementasi Multi Linked-List yaitu List pertama yang menampung nama-nama Instructor (Pengajar), dan List kedua yang menampung nama Course (Mata Kuliah). Setelah itu, bisa memasangkan antara Instructor dan Course yang diajarnya.

## Desain Multi Linked-List
Desain dapat dilihat di bawah ini : 

![Desain](https://drive.google.com/uc?id=1AT0awbT0aP8JOlCkhVjTddQ8z1LkR3OM)

Dan penjelasan setiap element sebagai berikut :

![Element](https://drive.google.com/uc?id=1g9p6ziLaq2EIVMmxCY0oVmU_5vkpZ6Nx)


## Penjelasan File-File dan Cara Run
Jika sudah install CodeBlocks, maka bisa langsung buka TubesInstructorCourse.cbp . Terdapat 3 file yang penting berisi kodingan, yaitu :

**1. inst_course.h**    : Header, berisi library, define, typedef, struct, dan seluruh function-procedure yang digunakan pada program

**2. inst_course.cpp**  : Source code, berisi penjelasan dari function-procedure yang dijelaskan pada header di atas

**3. main.cpp**         : Driver, berisi program utama yang menjalankan keseluruhan program

Selain itu, terdapat juga file .exe yang bisa langsung di-run yaitu di folder /bin/Debug yaitu TubesInstructorCourse.exe bagi kalian yang tidak memiliki IDE atau Text Editor yang mendukung untuk membuka file-file di atas

## Overview
Program langsung memberikan Menu di mana User bisa memasukkan angka untuk memilih fitur apa yang akan dilakukan oleh user lalu menekan Enter. Setelah selesai, jika ingin mengakhir program, maka User dapat memasukkan angka 16. Penjelasan fitur-fitur dari Menu akan dijelaskan di bawah.

## Fitur-fitur
**1. Print Instructor:**

Menampilkan ke layar List berisi Instructor yang ada


**2. Print Course:**

Menampilkan ke layar List berisi Course yang ada


**3. Print Course with Instructor:**

Menampilkan seluruh Course dan juga Instructor-instructor yang mengajar pada masing-masing Course


**4. Find Instructor:**

Mencari Instructor dan menampilkan apa-apa saja Course yang diajarnya


**5. Insert First Instructor:**

Menambahkan Instructor ke dalam List secara Insert-First


**6. Insert First Course:**

Menambahkan Course ke dalam List secara Insert-First


**7. Insert Last Instructor:**

Menambahkan Instructor ke dalam List secara Insert-Last


**8. Insert Last Course:**

Menambahkan Course ke dalam List secara Insert-Last


**9. Insert First Relasi:**

Menambahkan Relasi antara Instructor ke Course secara Insert-First


**10. Delete First Instructor:**

Menghapus Instructor dari List secara Delete-First


**11. Delete First Course:**

Menghapus Course dari List secara Delete-First


**12. Search Instructor:**

Mencari apakah Instructor ada di dalam List


**13. Search Course:**

Mencari apakah Course ada di dalam List


**14. Course with Most Instructor:**

Mencari sebuah Course yang diajarkan oleh Instructor paling banyak


**15. Instructor w/ >3 Course:**

Mencari Instructor yang mengajar lebih dari 3 Course


**16. Keluar:**

Exit dari program
