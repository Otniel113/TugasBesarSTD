#ifndef INST_COURSE_H_INCLUDED
#define INST_COURSE_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#define info(P) P->info
#define first(L) L.first
#define nextC(P) P->nextC
#define nextI(P) P->nextI
#define nextR(P) P->nextR
#define firstR(P) P->firstR
#define NIL NULL

using namespace std;

typedef string infotype;
typedef struct elmtInstructor *addr1;
typedef struct elmtCourse *addr2;
typedef struct elmtRelasi *addr3;

struct elmtInstructor{
    infotype info;
    addr1 nextI;
    addr3 firstR;
};

struct elmtCourse{
    infotype info;
    addr2 nextC;
};

struct elmtRelasi{
    addr2 nextC;
    addr3 nextR;
};

struct listInstructor{
    addr1 first;
};

struct listCourse{
    addr2 first;
};


/**Create List*/
void create2List(listInstructor &L1, listCourse &L2);

/**Alokasi*/
addr1 createNewInstructor(infotype X);
addr2 createNewCouse(infotype X);
addr3 createNewRelasi();

/**Insert First*/
void insertfirstInstructor(listInstructor &L1,addr1 P);
void insertFirstCourse(listCourse &L2,addr2 P);
void insertFirstRelasi(listInstructor L1, listCourse L2, infotype X, infotype Y);

/**Insert Last*/
void insertLastInstructor(listInstructor &L1, addr1 P);
void insertLastCourse(listCourse &L2, addr2 P);

/**Delete First*/
void deleteFirstInstructor(listInstructor &L1);
void deleteFirstCourse(listInstructor, listCourse &L2);



/**Print List*/
void printInstructor(listInstructor L1);
void printCourse(listCourse L2);
void printCourseWithInst(listInstructor L1, listCourse L2);
void findInstructor(listInstructor L1, listCourse L2, infotype X);

/**Searching*/
addr1 searchInstructor(listInstructor L1, infotype X);
addr2 searchCourse(listCourse L2, infotype X);
addr2 mostInstructors(listInstructor L1, listCourse L2);
addr1 instMoreThen3(listInstructor L1);

/**Menu*/
void menuUtama();
void menuPilihan(int pil, listInstructor &L1, listCourse &L2);

#endif // INST_COURSE_H_INCLUDED
