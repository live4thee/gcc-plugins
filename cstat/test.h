#ifndef test_h__
#define test_h__

#if _MSC_VER > 1200
enum  { THIS };
static int i = 0;
#else
enum  { THAT };
static int i = 1;
#endif

#endif
