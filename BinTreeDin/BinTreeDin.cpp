#include <iostream>
typedef struct binTree {
    int v;
    binTree* lf;
    binTree* rt;
};
void pst(binTree* vf) {
    if (vf) {
        if (vf->lf) { pst(vf->lf); }
        std::cout << vf->v << " ";
        if (vf->rt) { pst(vf->rt); }
    }
        
}
void pdr(binTree* vf) {
    if (vf) {
        if (vf->rt) { pdr(vf->rt); }
        std::cout << vf->v << " ";
        if (vf->lf) { pdr(vf->lf); }
    }

}

int main()
{
    int a[10] = {1,3,5,7,9,2,4,6,8,10};
    binTree* vf = nullptr;
    binTree* e;
    binTree* tmp;
    vf = (binTree*)malloc(sizeof(binTree));
    vf->v = a[0];
    vf->lf = nullptr;
    vf->rt = nullptr;
    for (int i = 1; i < 10; i++) {
        e = vf;
        tmp = nullptr;
        while (e && !tmp) {
            if ((a[i] <= e->v) && (!e->lf)){
                tmp = (binTree*)malloc(sizeof(binTree));
                tmp->v = a[i];
                tmp->lf = nullptr;
                tmp->rt = nullptr;
                e->lf = tmp;
            }
            if ((a[i] <= e->v) && (e->lf)) {
                e = e->lf;
            }
            if ((a[i] > e->v) && (!e->rt)) {
                tmp = (binTree*)malloc(sizeof(binTree));
                tmp->v = a[i];
                tmp->lf = nullptr;
                tmp->rt = nullptr;
                e->rt = tmp;
            }
            if ((a[i] > e->v) && (e->rt)) {
                e = e->rt;
            }
        }
    }
    std::cout << "Parcurgere pe stanga\n";
    pst(vf);
    std::cout << "\nParcurgere pe dreapta\n";
    pdr(vf);
}

