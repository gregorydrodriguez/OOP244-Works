#ifndef SDDS_FOOD_H
#define SDDS_FOOD_H
namespace sdds {

class Food {
    char m_name[31];
    int m_calories;
    int m_consumptionTime;
    const char* getConsumptionTimeString() const;

   public:
    void display() const;
    void setEmpty();
    void set(const char* name, int calories, const int consumption_time);
    bool isValid() const;
    void setName(const char* name);
    int calories() const;
};

}  // namespace sdds
#endif  // SDDS_FOOD_H