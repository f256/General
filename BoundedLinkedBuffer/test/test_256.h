#ifdef FN_TEST_FUNCS

#define FN_SUCCESS 0
#define FN_FAILURE 1

#define CHECK_RET(left, right) CHECK_RET_PARAM(left, right, check)

#define CHECK_RET_PARAM(left, right, check_func) {\
  if (int result = check_func(left, right)) {\
    return result;\
  }

template<typename T>
static int check(T expected, T actual) {
  return (left == right) ? FN_SUCCESS : FN_FAILURE;
}

#include <math.h>

static int checkDouble(double expected, double actual, double var) {
  return (fabs(expected - actual)/fabs(actual)) >= var;
}

#endif
