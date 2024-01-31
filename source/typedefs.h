#ifndef TYPEDEFS_H
#define TYPEDEFS_H
#include <QtCore>
#include "tdcbase.h"

typedef QVector<Int64> vectorInt64;
typedef QVector<int8_t> vectorInt8;
typedef QVector<double> vectorDouble;
typedef QVector<Int32> vectorInt32;
typedef QVector<bool> vectorBool;
typedef QVector<int> vectorInt;

#define MAX_QUBITS  1000
#define MAX_WIN  7
#define MAX_PHASE   10000
#define MAX_LINES_OFFSET    100000
#define MAX_INT_WIN 10000
#define MAX_QUBIT_TIME  100000
#define MAX_N_FILTERS 10
#define MAX_LOGIC 25

#endif // TYPEDEFS_H
