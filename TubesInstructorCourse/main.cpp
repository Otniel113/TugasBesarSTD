#include "inst_course.h"

int main()
{
    listInstructor L1;
    listCourse L2;
    addr1 P;
    addr2 Q;
    int pil;

    create2List(L1,L2);

    do{
        menuUtama();
        cin >> pil;
        menuPilihan(pil,L1,L2);
        system("PAUSE");
        system("CLS");
    }while(pil != 16);
    cout << "\n=============================END OF PROGRAM===============================" << endl;

    return 0;
}
