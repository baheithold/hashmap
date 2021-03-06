/*
 *  Author: Brett Heithold
 *  File:   test-htable.c
 *  Last Modified:  11 Feb 2020
 */


#include "hashmap.h"
#include "integer.h"
#include "real.h"
#include "string.h"

#include <assert.h>


int prehashSTRING(void *s) {
    assert(s != NULL);
    int strLength = lengthSTRING(s);
    char *str = getSTRING(s);
    int result = 0;
    for (int i = 0; i < strLength; ++i) {
        result += str[i];
    }
    printf("result: %d\n", result);
    return result;
}


int main(void) {
    // Create and initialize the HASHMAP
    HASHMAP *map = newHASHMAP(prehashSTRING, compareSTRING);
    setHASHMAPdisplayKey(map, displaySTRING);
    setHASHMAPdisplayValue(map, displayINTEGER);
    setHASHMAPfreeKey(map, freeSTRING);
    setHASHMAPfreeValue(map, freeINTEGER);
    // display the map with debug info
    displayHASHMAP(map, stdout);
    printf("\n");
    // play with some insertions
    STRING *k0 = newSTRING("var0");
    INTEGER *v0 = newINTEGER(0);
    STRING *k1 = newSTRING("var1");
    INTEGER *v1 = newINTEGER(1);
    STRING *k2 = newSTRING("test");
    INTEGER *v2 = newINTEGER(2);
    insertHASHMAP(map, k0, v0);
    insertHASHMAP(map, k1, v1);
    insertHASHMAP(map, k2, v2);
    // display the map with debug info
    displayHASHMAP(map, stdout);
    printf("\n");
    STRING *f0 = newSTRING("var0");
    printf("key: var0 ... found? %d\n", containsKey(map, f0));
    // Remove f0 from map
    STRING *k = removeHASHMAP(map, f0);
    displaySTRING(k, stdout);
    printf("\n");
    freeSTRING(k);
    displayHASHMAP(map, stdout);
    printf("key: var0 ... found? %d\n", containsKey(map, f0));
    freeSTRING(f0);
    printf("\n");
    freeHASHMAP(map);
    return 0;
}
