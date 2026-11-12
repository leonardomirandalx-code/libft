*This project has been created as part of the 42 curriculum by leomiran.*

## Description

This project aims to build a set of tools that I am going to use throughout the Common Core from now on. While building these functions, I learned the behaviour and inner workings of some of the core functions of the C standard library (libc), and even created my own functions. With these tools, it is possible to manipulate characters, strings, memory, linked lists and file descriptors, allowing more complex functions to be built on top of them.

All these functions are compiled into a static library, `libft.a`, which can be seen as a mechanic's toolbox. It is divided into three parts:

- **Part 1 – Libc functions:** I replicated some of the core functions of the libc, with the same behaviour as the originals, so that I can rely on them as a base whenever I need them from now on.
- **Part 2 – Additional functions:** I created functions that do not exist in the libc (or exist in a different form), mainly for string manipulation and for writing to file descriptors, often using the tools from the first part.
- **Part 3 – Linked lists:** I discovered a new kind of data structure, the linked list, which can grow and shrink one element at a time, without having to know its size in advance or reallocate everything. These functions mostly build on each other, such as `ft_lstmap` relying on `ft_lstnew` and `ft_lstclear`.

## Instructions

### Requirements

<<<<<<< HEAD
- ### Requirements

- A C compiler, such as `gcc` or `clang`.
=======
- A C compiler, such as `cc`.
>>>>>>> refs/remotes/origin/main
- GNU Make.

### Compilation

To build the library, run the following command in the project directory:

```bash
make
```

This compiles every source file with the flags `-Wall -Wextra -Werror` and creates the static library `libft.a`.

The Makefile has the following rules:

- `make` or `make all`: compiles the library.
- `make clean`: removes the object files (`.o`).
- `make fclean`: removes the object files and `libft.a`.
- `make re`: removes everything and compiles the library again.

### Using the library

Include the header in your source file:

```c
#include "libft.h"
```

Then compile your program together with the library:

```bash
cc -Wall -Wextra -Werror main.c libft.a -o program
./program
```

## Library description

### Part 1 - Libc functions

- `ft_isalpha`: Returns 1 if the character passed as a parameter is alphabetical (from `'a'` to `'z'` or `'A'` to `'Z'`) in the ASCII table, and 0 otherwise.
- `ft_isdigit`: Returns 1 if the character passed as a parameter is a digit (from `'0'` to `'9'`) in the ASCII table, and 0 otherwise.
- `ft_isalnum`: Returns 1 if the character passed as a parameter is alphabetical or a digit (from `'a'` to `'z'`, from `'A'` to `'Z'` or from `'0'` to `'9'`) in the ASCII table, and 0 otherwise.
- `ft_isascii`: Returns 1 if the value passed as a parameter is a character in the ASCII table (from 0 to 127), and 0 otherwise.
- `ft_isprint`: Returns 1 if the character passed as a parameter is printable (from 32, the space `' '`, to 126, `'~'`) in the ASCII table, and 0 otherwise.
- `ft_strlen`: Returns the number of characters in the string passed as a parameter, counting until the null terminator (`'\0'`), which is not included in the count.
- `ft_memset`: Fills the first `n` bytes of the memory area pointed to by `s` with the value `c`, converted to an `unsigned char`, and returns a pointer to `s`.
- `ft_bzero`: Sets the first `n` bytes of the memory area pointed to by `s` to zero (`'\0'`). It does not return a value.
- `ft_memcpy`: Copies `n` bytes from the memory area `src` to the memory area `dest`, and returns a pointer to `dest`. The memory areas must not overlap; for that case, `ft_memmove` should be used.
- `ft_memmove`: Copies `n` bytes from the memory area `src` to the memory area `dest`, and returns a pointer to `dest`. Unlike `ft_memcpy`, the memory areas may overlap: the copy direction is chosen so that the source bytes are never overwritten before being read.
- `ft_strlcpy`: Copies up to `dsize - 1` characters from the string `src` to `dst`, null-terminating the result (unless `dsize` is 0). It returns the length of `src`, so truncation occurred if the return value is greater than or equal to `dsize`.
- `ft_strlcat`: Appends the string `src` to the end of the string `dst`, copying at most `size - len(dst) - 1` characters and always null-terminating the result, as long as `size` is greater than the length of `dst`. It returns the length of the string it tried to create: the initial length of `dst` (at most `size`) plus the length of `src`. If the return value is greater than or equal to `size`, the result was truncated.
- `ft_toupper`: Converts a lowercase letter (from `'a'` to `'z'`) to its uppercase equivalent in the ASCII table. If the character is not a lowercase letter, it is returned unchanged.
- `ft_tolower`: Converts an uppercase letter (from `'A'` to `'Z'`) to its lowercase equivalent in the ASCII table. If the character is not an uppercase letter, it is returned unchanged.
- `ft_strchr`: Returns a pointer to the first occurrence of the character `c` (converted to a `char`) in the string `s`. The null terminator is considered part of the string, so searching for `'\0'` returns a pointer to the end of `s`. If the character is not found, it returns `NULL`.
- `ft_strrchr`: Returns a pointer to the last occurrence of the character `c` (converted to a `char`) in the string `s`. The null terminator is considered part of the string, so searching for `'\0'` returns a pointer to the end of `s`. If the character is not found, it returns `NULL`.
- `ft_strncmp`: Compares at most the first `n` characters of the strings `s1` and `s2`, treating each character as an `unsigned char`. It returns 0 if they are equal, a negative value if the first differing character of `s1` is lower than that of `s2`, and a positive value if it is greater. The comparison stops at the first null terminator.
- `ft_memchr`: Scans the first `n` bytes of the memory area pointed to by `s` for the first occurrence of the byte `c` (converted to an `unsigned char`), and returns a pointer to it. Unlike `ft_strchr`, it does not stop at a null terminator. If the byte is not found, it returns `NULL`.
- `ft_memcmp`: Compares the first `n` bytes of the memory areas `s1` and `s2`, treating each byte as an `unsigned char`. It returns 0 if they are equal, or the difference between the first pair of differing bytes otherwise. Unlike `ft_strncmp`, it does not stop at a null terminator.
- `ft_strnstr`: Searches for the first occurrence of the string `little` in the string `big`, looking at no more than `len` characters. If `little` is an empty string, it returns `big`. If `little` is not found, it returns `NULL`; otherwise, it returns a pointer to the first character of the occurrence.
- `ft_atoi`: Converts the beginning of the string `nptr` to an `int`. It skips the leading whitespace characters, accepts one optional `'+'` or `'-'` sign, and reads the digits until the first character that is not a digit.
- `ft_calloc`: Allocates memory for an array of `nmemb` elements of `size` bytes each, sets all of its bytes to zero, and returns a pointer to it. It returns `NULL` if the allocation fails or if `nmemb * size` would overflow.
- `ft_strdup`: Returns a pointer to a new string, allocated with `malloc`, which is a copy of the string `s`. It returns `NULL` if the allocation fails.

### Part 2 - Additional functions

- `ft_substr`: Returns a new string, allocated with `malloc`, containing at most `len` characters of the string `s`, starting at index `start`. If `start` is beyond the end of `s`, it returns an empty string. It returns `NULL` if the allocation fails.
- `ft_strjoin`: Returns a new string, allocated with `malloc`, which is the result of joining `s1` and `s2`, in that order. It returns `NULL` if the allocation fails.
- `ft_strtrim`: Returns a copy of the string `s1`, allocated with `malloc`, with the characters found in `set` removed from its beginning and its end. It returns `NULL` if the allocation fails.
- `ft_split`: Splits the string `s` into words, using the character `c` as a delimiter, and returns an array of new strings, allocated with `malloc`, ending with a `NULL` pointer. If an allocation fails, everything allocated so far is freed and it returns `NULL`.
- `ft_itoa`: Converts the integer `n` into a string, allocated with `malloc`, including the `'-'` sign for negative numbers. It handles every `int` value, including `INT_MIN`. It returns `NULL` if the allocation fails.
- `ft_strmapi`: Applies the function `f` to each character of the string `s`, passing its index as the first argument, and returns a new string, allocated with `malloc`, with the results. It returns `NULL` if the allocation fails.
- `ft_striteri`: Applies the function `f` to each character of the string `s`, passing its index and the address of the character, so that the original string can be modified directly. It does not return a value.
- `ft_putchar_fd`: Writes the character `c` to the file descriptor `fd`.
- `ft_putstr_fd`: Writes the string `s` to the file descriptor `fd`.
- `ft_putendl_fd`: Writes the string `s` to the file descriptor `fd`, followed by a newline (`'\n'`).
- `ft_putnbr_fd`: Writes the integer `n` to the file descriptor `fd`, including the `'-'` sign for negative numbers. It handles every `int` value, including `INT_MIN`.

### Part 3 - Linked lists

- `ft_lstnew`: Creates a new node, allocated with `malloc`, with `content` as its content and `next` set to `NULL`. It returns the new node, or `NULL` if the allocation fails.
- `ft_lstadd_front`: Adds the node `new` at the beginning of the list, so that it becomes the new first node of `*lst`.
- `ft_lstsize`: Returns the number of nodes in the list. An empty list (`NULL`) has a size of 0.
- `ft_lstlast`: Returns the last node of the list, or `NULL` if the list is empty.
- `ft_lstadd_back`: Adds the node `new` at the end of the list. If the list is empty, `new` becomes its first node.
- `ft_lstdelone`: Frees the content of the node `lst` using the function `del`, and then frees the node itself. The next node is not freed.
- `ft_lstclear`: Deletes and frees every node of the list, using the function `del` and `free`, and sets the pointer to the list (`*lst`) to `NULL`.
- `ft_lstiter`: Applies the function `f` to the content of each node of the list.
- `ft_lstmap`: Creates a new list, applying the function `f` to the content of each node of `lst`. The function `del` is used to free the content of a node if needed. If an allocation fails, the new list is cleared and it returns `NULL`.

## Resources

- LINUX manual pages: the original behaviour of each libc function, such as `man 3 memmove` or `man 3 strlcpy`.
- The Libft subject and the peer learning with other students at 42 Lisboa.

### Use of AI

I used AI (Claude) as a tutor, never to write the functions for me. It was used for:

- **Understanding concepts:** asking questions about pointers, `void *`, type conversions, operator precedence, memory overlap and linked lists, until I was able to explain them in my own words.
- **Reviewing my code:** after writing each function by myself, I asked it to point out where there were mistakes or missing edge cases (such as an empty list in `ft_lstadd_back`), without giving me the solution, so that I could fix them on my own.
- **Writing this README:** helped me with the English wording of some function descriptions, always checked against my own understanding of each function.
