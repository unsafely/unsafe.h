#include <unsafe.h>

unsafe struct s
{
    double f1;
    unsafe int f2;
};

unsafe int get_f2(struct s);

unsafe int get_f2(struct s s1)
{
    unsafe
    {
        return s1.f2;
    }
}

int main()
{
    struct s s1;
    unsafe int i1 = get_f2(s1);

    return i1;
}