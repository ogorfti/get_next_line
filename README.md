## 🗣️ About

> It's the second project at 1337. It involved creating a function in C that reads a line from a file descriptor, making it an efficient way to read large files where the size is not known. This project helped me gain experience in memory optimization and file handling, and the resulting function has proven to be a valuable tool for my future programming projects.

### 🛠️ Usage

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

If you're on Linux, you may as well need the following flags:

```shell
-D ARG_MAX="sysconf(_SC_ARG_MAX)" -D OPEN_MAX=1024
```

### Third-party testers

* [gnlTester](https://github.com/Tripouille/gnlTester)
* [mrjvs/42cursus_gnl_tests](https://github.com/mrjvs/42cursus_gnl_tests)
* [Hellio404/Get_Next_Line_Tester](https://github.com/Hellio404/Get_Next_Line_Tester)
* [saarikoski-jules/gnl_unit_tests](https://github.com/saarikoski-jules/gnl_unit_tests)
* [charMstr/GNL_lover](https://github.com/charMstr/GNL_lover)
* [Mazoise/42TESTERS-GNL](https://github.com/Mazoise/42TESTERS-GNL)
