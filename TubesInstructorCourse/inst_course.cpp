#include "inst_course.h"

/**==============================CREATE LIST==============================*/
void create2List(listInstructor &L1, listCourse &L2){
    first(L1) = NIL;
    first(L2) = NIL;
}

/**==============================ALOKASI==============================*/
addr1 createNewInstructor(infotype X){
    addr1 P = new elmtInstructor;
    info(P) = X;
    nextI(P) = NIL;
    firstR(P) = NIL;
    return P;
}

addr2 createNewCouse(infotype X){
    addr2 P = new elmtCourse;
    info(P) = X;
    nextC(P) = NIL;
    return P;
}

addr3 createNewRelasi(){
    addr3 P = new elmtRelasi;
    nextR(P) = NIL;
    nextC(P) = NIL;
    return P;
}

/**==============================INSERT FIRST ==============================*/
void insertfirstInstructor(listInstructor &L1, addr1 P){
    if (first(L1) != NULL){
        nextI(P) = first(L1);
        first(L1) = P;
    } else {
        first(L1) = P;
    }
}

void insertFirstCourse(listCourse &L2,addr2 P){
    if (first(L2) != NULL){
        nextC(P) = first(L2);
        first(L2) = P;
    } else {
        first(L2) = P;
    }
}

void insertFirstRelasi(listInstructor L1, listCourse L2, infotype X, infotype Y){
    addr1 P = searchInstructor(L1,X);
    addr2 Q = searchCourse(L2,Y);
    if (P != NIL && Q!=NIL){
        addr3 R = createNewRelasi();
        if (firstR(P) == NIL){
            firstR(P) = R;
            nextC(R) = Q;
        }else{
            nextR(R) = firstR(P);
            firstR(P) = R;
            nextC(R) = Q;
        }
        cout << "\nRelasi berhasil ditambahkan" << endl;
    }else{
        cout << "\nTidak bisa menambahkan relasi" << endl;
        cout << "Karena data yang dimasukkan tidak ada dalam list" << endl;
    }
}


/**==============================INSERT LAST==============================*/
void insertLastInstructor(listInstructor &L1, addr1 P){

    addr1 Q = first(L1);

    if (first(L1) != NULL){
        while(nextI(Q) != NULL){
            Q = nextI(Q);
        }
        nextI(Q) = P;
    } else{
        insertfirstInstructor(L1,P);
    }
}

void insertLastCourse(listCourse &L2, addr2 P){

    addr2 Q = first(L2);

    if (first(L2) != NULL){
        while(nextC(Q) != NULL){
            Q = nextC(Q);
        }
        nextC(Q) = P;
    }else{
        insertFirstCourse(L2,P);
    }
}

/**==============================DELETE FIRST==============================*/
void deleteFirstInstructor(listInstructor &L1){
    if (first(L1) != NULL){
        addr1 P = first(L1);

            if(nextI(first(L1)) == NULL){
                if (firstR(P) != NIL){
                    firstR(P) = NIL;
                }
                first(L1) = NULL;
            }else{
                if (firstR(P) != NIL){
                    firstR(P) = NIL;
                }
                first(L1) = nextI(first(L1));
                nextI(P) = NULL;
        }
    }else{
        cout<<"DAFTAR INSTRUCTOR KOSONG"<<endl;
    }
}

void deleteFirstCourse(listInstructor L1, listCourse &L2){
    addr2 P = first(L2);
    addr1 Q = first(L1);
    addr3 R;

    while (Q != NIL){
        R = firstR(Q);
            while (R != NIL){
                if (nextC(R) == P){
                    nextC(R) = NIL;
                }
                R = nextR(R);
            }
        Q = nextI(Q);
    }

    if (first(L2) != NULL){
        if(nextC(first(L2)) == NULL){
            first(L2) = NULL;
        }else{
            first(L2) = nextC(first(L2));
            nextC(P) = NULL;
        }
    }
    else{
        cout<<"DAFTAR MATA KULIAH KOSONG"<<endl;
    }
}



/**==============================PRINT==============================*/
void printInstructor(listInstructor L1){
    addr1 P = first(L1);
    int i = 1;
    cout << "\nDAFTAR INSTRUCTOR" << endl;
    if (first(L1) != NIL){
        while (P != NIL){
            cout << i << ". " << info(P) << endl;
            P = nextI(P);
            i++;
        }
    }else{
        cout << "DAFTAR INSTRUCTOR KOSONG" << endl;
    }
}

void printCourse(listCourse L2){
    addr2 P = first(L2);
    int i = 1;
    cout << "\nDAFTAR COURSE" << endl;
    if (first(L2) != NIL){
        while (P != NIL){
            cout << i << ". " << info(P) << endl;
            P = nextC(P);
            i++;
        }
    }else{
        cout << "DAFTAR COURSE KOSONG" << endl;
    }
}

void printCourseWithInst(listInstructor L1, listCourse L2){
    addr1 P;
    addr2 Q = first(L2);
    addr3 R;

    cout << "\n===============PRINT COURSE WITH INSTRUCTORS===============" << endl;

    while (Q!= NIL){
        cout << "\nCourse " << info(Q) << " diajarkan oleh : " << endl;
        P = first(L1);
        while (P != NIL){
            R = firstR(P);
                while (R != NIL){
                    if (nextC(R) == Q){
                        cout << info(P) << endl;
                    }
                    R = nextR(R);
                }
            P = nextI(P);
        }
        Q = nextC(Q);
    }
}

void findInstructor(listInstructor L1, listCourse L2, infotype X){
    addr1 P;
    addr2 Q = searchCourse(L2,X);
    addr3 R;

    if (Q != NIL){
        cout << "\nCourse " << info(Q) << " diajarkan oleh : " << endl;
        P = first(L1);
        while (P != NIL){
            R = firstR(P);
                while (R != NIL){
                    if (nextC(R) == Q){
                        cout << info(P) << endl;
                    }
                    R = nextR(R);
                }
            P = nextI(P);
        }
    }else{
        cout << "\nTIDAK DAPAT MENAMPILKAN HASIL KARENA COURSE TIDAK ADA" << endl;
    }
}



/**==============================SEARCHING==============================*/
addr1 searchInstructor(listInstructor L1, infotype X){
    addr1 P = first(L1);
    while (P != NIL){
        if (info(P) == X){
            return P;
            break;
        }else{
            P = nextI(P);
        }
    }
    if (P == NIL){
        return P;
    }
}

addr2 searchCourse(listCourse L2, infotype X){
    addr2 P = first(L2);
    while (P != NIL){
        if (info(P) == X){
            return P;
            break;
        }else{
            P = nextC(P);
        }
    }
    if (P == NIL){
        return P;
    }
}

addr2 mostInstructors(listInstructor L1, listCourse L2){
    addr1 P;
    addr2 Q = first(L2);
    addr3 R;
    addr2 terbanyak = NIL;
    int i;
    int temp = 0;

    while (Q!= NIL){
        P = first(L1);
        i = 0;
        while (P != NIL){
            R = firstR(P);
                while (R != NIL){
                    if (nextC(R) == Q){
                        i++;
                    }
                    R = nextR(R);
                }
            P = nextI(P);
        }
        if (i>temp){
            temp = i;
            terbanyak = Q;
        }
        Q = nextC(Q);
    }

    return terbanyak;
}

addr1 instMoreThen3(listInstructor L1){
    addr1 P = first(L1);
    addr1 hasilReturn = NIL;
    addr3 R;
    int i;

    while (P != NIL){
        R = firstR(P);
        i = 0;
            while (R!=NIL){
                R = nextR(R);
                i++;
            }
        if (i>3){
            hasilReturn = P;
            return hasilReturn;
            break;
        }
        P = nextI(P);
    }

    if (hasilReturn == NIL){
        return hasilReturn;
    }
}


/**==============================MENU==============================*/
void menuUtama(){
    cout << "==========SELAMAT DATANG DI INSTRUCTOR - COURSE==========" << endl;
    cout << "Silakan pilih menu yang ingin Anda lakukan : " << endl;
    cout << "\n---PRINT---" << endl;
    cout << "1. Print Instructor" << endl;
    cout << "2. Print Course" << endl;
    cout << "3. Print Course with Instructor" << endl;
    cout << "4. Find Instructor" << endl;
    cout << "\n---MENAMBAH INSTRUCTOR / COURSE---" << endl;
    cout << "5. Insert First Instructor" << endl;
    cout << "6. Insert First Course" << endl;
    cout << "7. Insert Last Instructor" << endl;
    cout << "8. Insert Last Course" << endl;
    cout << "\n---MENAMBAH RELASI ANTARA KEDUANYA---" << endl;
    cout << "9. Insert First Relasi" << endl;
    cout << "\n---MENGHAPUS INSTRUCTOR / COURSE---" << endl;
    cout << "10. Delete First Instructor" << endl;
    cout << "11. Delete First Course" << endl;
    cout << "\n---SEARCHING---" << endl;
    cout << "12. Search Instructor" << endl;
    cout << "13. Search Course" << endl;
    cout << "14. Course w/ Most Instructors" << endl;
    cout << "15. Instructor w/ More Than 3 Courses" << endl;
    cout << "\n---EXIT---" << endl;
    cout << "16. Keluar" << endl;
    cout << "\nPilihan Anda : ";
}

void menuPilihan(int pil, listInstructor &L1, listCourse &L2){
    infotype namaInstructor, namaCourse;
    addr1 P;
    addr2 Q;
    switch(pil){
        case 1 : printInstructor(L1);
                 break;
        case 2 : printCourse(L2);
                 break;
        case 3 : printCourseWithInst(L1,L2);
                 break;
        case 4 : cout << "\nMasukkan Nama Instructor yang ingin dicari Course yang diajarnya : ";
                 cin >> namaInstructor;
                 findInstructor(L1,L2,namaInstructor);
                 break;
        case 5 : cout << "\nMasukkan Nama Instructor yang ingin ditambahkan : ";
                 cin >> namaInstructor;
                 P = createNewInstructor(namaInstructor);
                 insertfirstInstructor(L1,P);
                 break;
        case 6 : cout << "\nMasukkan Nama Course yang ingin ditambahkan : ";
                 cin >> namaCourse;
                 Q = createNewCouse(namaCourse);
                 insertFirstCourse(L2,Q);
                 break;
        case 7 : cout << "\nMasukkan Nama Instructor yang ingin ditambahkan : ";
                 cin >> namaInstructor;
                 P = createNewInstructor(namaInstructor);
                 insertLastInstructor(L1,P);
                 break;
        case 8 : cout << "\nMasukkan Nama Course yang ingin ditambahkan : ";
                 cin >> namaCourse;
                 Q = createNewCouse(namaCourse);
                 insertLastCourse(L2,Q);
                 break;
        case 9 : cout << "Masukkan Nama Instructor dan Course yang mau dipasangkan : " << endl;
                 cout << "Nama Instructor : ";
                 cin >> namaInstructor;
                 cout << "Nama Course : ";
                 cin >> namaCourse;
                 insertFirstRelasi(L1,L2,namaInstructor,namaCourse);
                 break;
        case 10 : deleteFirstInstructor(L1);
                  break;
        case 11 : deleteFirstCourse(L1,L2);
                  break;
        case 12 : cout << "Masukkan Nama Instructor yang mau dicari : ";
                  cin >> namaInstructor;
                  P = searchInstructor(L1,namaInstructor);
                  if (P != NIL){
                    cout << "Instructor bernama " << namaInstructor << " ditemukan" << endl;
                  }else{
                    cout << "Instructor tidak ditemukan" << endl;
                  }
                  break;
        case 13 : cout << "Masukkan Nama Course yang mau dicari : ";
                  cin >> namaCourse;
                  Q = searchCourse(L2,namaCourse);
                  if (Q != NIL){
                    cout << "Course " << namaCourse << " ditemukan" << endl;
                  }else{
                    cout << "Course tidak ditemukan" << endl;
                  }
                  break;
        case 14 : Q = mostInstructors(L1,L2);
                  if (Q != NIL){
                    cout << "Course yang diajarkan oleh Instructor terbanyak adalah " << info(Q) << endl;
                  }else{
                    cout << "Tidak ada List atau Relasi yang terbentuk" << endl;
                  }
                  break;
        case 15 : P = instMoreThen3(L1);
                  if (P!=NIL){
                    cout << "Instructor yang mengajarkan lebih dari 3 course adalah : " << info(P) << endl;
                  }else{
                    cout << "Tidak ada Instructor yang mengajar lebih dari 3 coourse" << endl;
                  }
                  break;
        case 16 : break;
        default : cout << "Tolong masukkan angka yang valid! " << endl;
                  break;
    }
}


