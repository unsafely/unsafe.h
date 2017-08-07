# `unsafe` keywrod in C/C++

### USAGE

```C++
#include <unsafe.h> /** include the header file **/

unsafe int func1(); /** declare an unsafe function **/

unsafe struct s1 {  /** or `struct s1 unsafe {` **/
  /** declare an unsafe struct with an unsafe field **/
  
  unsafe int f1;
};

unsafe struct s1 v1; /** decalre an unsafe variable **/

int v2 = unsafe func1(); /** call an unsafe function **/
```
