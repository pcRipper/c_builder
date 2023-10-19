#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAP_IN(array, size, func) \
  for (int i = 0; i < size; i++) { \
    array[i] = func(i, array[i]); \
  }


#endif