#ifndef MADE_SOLUTION_H
#define MADE_SOLUTION_H

#include <stdbool.h>
#include <stdint.h>


/**
 * Library-level functions.
 * You should use them in the main sections.
 */

#ifdef __cplusplus
extern "C" {
#endif

uint64_t convertToUint64(double number);

bool getBit(uint64_t number, uint8_t index);


bool checkForPlusZero(uint64_t number);

bool checkForMinusZero(uint64_t number);

bool checkForPlusInf(uint64_t number);

bool checkForMinusInf(uint64_t number);

bool checkForPlusNormal(uint64_t number);

bool checkForMinusNormal(uint64_t number);

bool checkForPlusDenormal(uint64_t number);

bool checkForMinusDenormal(uint64_t number);

bool checkForSignalingNan(uint64_t number);

bool checkForQuietNan(uint64_t number);


void classify(double number);

#ifdef __cplusplus
}
#endif

#endif //MADE_SOLUTION_H
