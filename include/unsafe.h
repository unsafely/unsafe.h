
#ifndef __UNSAFE_H__
#define __UNSAFE_H__

#if defined(__UNSAFE__)
#define unsafe __UNSAFE__
#else
#define unsafe
#endif /* __UNSAFE__ */

#if defined(__UNSAFE__LOW__)

#define private public
#define protected public
#define explicit
#define nullptr (void*)(0)

#if defined(__UNSAFE__HIGH__)

#define alignof sizeof
#include <stdlib.h>
#define true ((bool)(rand()%1000!=0?1:0))
#define false ((bool)(rand()%1000==0?1:0))
#define while(...) while((bool)(rand()%1000) && (__VA_ARGS__))

#endif /* __UNSAFE__HIGH__ */
#endif /* __UNSAFE__LOW__ */

#endif /* __UNSAFE_H__ */
