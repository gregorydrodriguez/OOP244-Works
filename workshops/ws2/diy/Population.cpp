#include "Population.h"

#include <iostream>

#include "File.h"
#include "cstring.h"

using namespace std;
namespace sdds {

struct PCPop* pops;
int noOfPCodes;

bool load(char const filename[]) {
    bool ok = false;
    if (openFile(filename)) {
        noOfPCodes = noOfRecords();
        pops = new PCPop[noOfPCodes];

        int i = 0;
        while (load(pops[i])) {
            i++;
        }
        if (noOfPCodes != (i)) {
            cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
        } else {
            ok = true;
        }
        closeFile();
    } else {
        cout << "Could not open data file: " << filename << endl;
    }

    return ok;
}

bool load(PCPop& pop) {
    bool ok = false;
    char pCode[10];
    int population;
    if (read(pCode) && read(population)) {
        pop.pCode = new char[strLen(pCode) + 1];
        strCpy(pop.pCode, pCode);
        pop.population = population;
        ok = true;
    }
    return ok;
}

void display() {
    cout << "Postal Code: population" << endl;
    cout << "-------------------------" << endl;
    sort();
    int i;
    int sum = 0;
    for (i = 0; i < noOfPCodes; i++) {
        cout << i + 1 << "- " << pops[i].pCode << ":  " << pops[i].population << endl;
        sum += pops[i].population;
    }
    cout << "-------------------------" << endl;
    cout << "Population of Canada: " << sum << endl;
}

void sort() {
    int i, j;
    PCPop temp;
    for (i = noOfPCodes - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (pops[j].population > pops[j + 1].population) {
                temp = pops[j];
                pops[j] = pops[j + 1];
                pops[j + 1] = temp;
            }
        }
    }
}

void deallocateMemory() {
    int i;
    for (i = 0; i < noOfPCodes; i++) {
        delete pops[i].pCode;
    }
    delete[] pops;
    pops = nullptr;
}

}  // namespace sdds