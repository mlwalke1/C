#include <fstream>

using namespace std;

class search{

  public:
    search(ifstream& inFile);
    void QuickSort();
    void seqSearch(ofstream& outFile, int data, float& num);
    void PrintArray(ofstream& outFile);
    void binSearch(ofstream& outFile, int data, float& num);
    void hashSort(int data);
    void hashSearch(ofstream& outData, int data, float& num);
    void doubHashSort(int data);
    void doubHashSearch(ofstream& outFile, int data, float& num);

  private:
    static const int tableSize = 20;
    static const int hashTableSize = 40;
    int idList[tableSize];
    int hashList[hashTableSize];
};
