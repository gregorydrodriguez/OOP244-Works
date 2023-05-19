#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H
namespace sdds {
   const int MAX_TITLE_LENGTH = 50;
   const int MAX_QUANTITY_VALUE = 50;
   struct ShoppingRec {
      char m_title[MAX_TITLE_LENGTH + 1];
      int m_quantity;
      bool m_bought;
   };

   ShoppingRec getShoppingRec();
   void displayShoppingRec(const ShoppingRec* shp);
   void toggleBoughtFlag(ShoppingRec* rec);
   bool isShoppingRecEmpty(const ShoppingRec* shp);
} // namespace sdds
#endif