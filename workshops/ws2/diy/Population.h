#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {

struct PCPop {
    char* pCode;
    int population;
};
bool load(char const filename[]);
bool load(PCPop& pop);
void sort();
void display();
void deallocateMemory();

}  // namespace sdds
#endif  // SDDS_POPULATION_H_