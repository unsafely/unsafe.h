# `unsafe` keywrod in C/C++

`unsafe.h` provide a way to specify the potential unsafe operations, include memory-unsafe, thread-unsafe, type-unsafe and any other unsafe operations. 

It is recommended to use it widely in C/C++ projects because it is very helpful to remind people to be careful with bad code. We strongly recommend someone propose this to C/C++ standard commitee as a built-in language feature.

Please see [Rules](#Rules) and [Examples](#Examples) section for details about how to use this keywords.

We are currently working on implement an unsafe checker to ensure everyone following the rule, includes the detection of unsafe operations and suggestions of unsafe keyword.

## Rules

1. DO use `unsafe` as very first modifier for every unsafe entity (functions, types, variables and expressions).
2. DO use `unsafe` in a transitive way. i.e. A function with unsafe expression should be unsafe.
3. DO use `unsafe` as soon as possible in every case (type unsafe, memory unsafe, thread unsafe and any other potential unsafe operations like unchecked fixed size arithmetic).
4. DO include `unsafe.h` as very first header file when the source file contains unsafe operation.
5. It is RECOMMENDED to NOT include `unsafe.h` in a header file when using the keyword, to make sure the user knows they need to include `unsafe.h` at very first to indicates the source file contains potential unsafe operations.

## Examples

```C++
#include <unsafe.h>

/* this will be an unsafe struct */
unsafe struct s
{
    double f1;
    unsafe int f2;
};

/* this is unsafe because it accesses an unsafe struct */
unsafe int get_f2(struct s);

/* this is unsafe because it has unsafe statements */
unsafe int get_f2(struct s s1)
{
    /* this statement is unsafe because it accesses an unsafe field */
    unsafe
    {
        return s1.f2;
    }
}

/* this is unsafe because it has unsafe expression */
unsafe int main()
{
    struct s s1;
    /* this is unsafe because it captures an unsafe function call */
    unsafe int i1 = get_f2(s1);

    return i1;
}
```