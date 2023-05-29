# ifndef作用

## ifndef作用

a.h

```
#include <iostream>
#include "b.h"

int i = 5;
Boy b;

struct Girl
{
    int age;
};
```

b.h

```
#include <iostream>

struct Boy
{
    int age;
};
```

main.cpp

```
#include "a.h"
#include "b.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    /* code */
    Boy c;
    c.age = 10;
    Girl g;
    g.age = 20;
    return 0;
}

```

报错：

![image-20230525154727635](C:\Users\henry0408\AppData\Roaming\Typora\typora-user-images\image-20230525154727635.png)

改正：

b.h中

```
#ifndef PERSON_H
#define PERSON_H
#include <iostream>

struct Boy
{
    int age;
};
#endif
```

