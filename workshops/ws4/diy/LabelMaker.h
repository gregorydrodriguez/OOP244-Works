#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds {
class LabelMaker {
    Label** m_labels;
    int m_noOfLabels;

   public:
    LabelMaker(int noOfLabels);
    ~LabelMaker();
    void readLabels();
    void printLabels();
};
}  // namespace sdds
#endif  // SDDS_LABELMAKER_H