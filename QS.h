#ifndef QS_H_
#define QS_H_

#include "QSInterface.h"

class QS:public QSInterface
{
public:
    QS(){ array = NULL; size = 0; capacity = 0;};
    virtual ~QS()
    {
        clear();
    };
    virtual void sortAll();
    virtual int medianOfThree(int left, int right);
    virtual int partition(int left, int right, int pivotIndex);
    virtual string getArray();
    virtual int getSize();
    virtual void addToArray(int value);
    virtual bool createArray(int capacity);
    virtual void clear();

private:
    void Sort_All_Recursive(int left, int right);
    void swap(int left, int right);
    int* array;
    int size;
    int capacity;
    
};
#endif /* QS_H_ */