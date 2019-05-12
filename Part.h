#include <string>

class Part {          // simple storage class
    public:
        Part(int e, std::string desc);
        Part();
        int getID();
        void setID(int num);
        std::string getDescription();
        void setDescription(std::string desc);
    private:
        int id;
        std::string description;
};
