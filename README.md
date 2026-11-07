*This project has been created as part of the 42 curriculum by leomiran.*

## Description

This project aims to build a set of tools that I am going to use throughout the Common Core from now on. While building these functions, I learned the behaviour and inner workings of some of the core functions of the C standard library (libc), and even created my own functions. With these tools, it is possible to manipulate characters, strings, memory, linked lists and file descriptors, allowing more complex functions to be built on top of them.

All these functions are compiled into a static library, `libft.a`, which can be seen as a mechanic's toolbox. It is divided into three parts:

- **Part 1 – Libc functions:** I replicated some of the core functions of the libc, with the same behaviour as the originals, so that I can rely on them as a base whenever I need them from now on.
- **Part 2 – Additional functions:** I created functions that do not exist in the libc (or exist in a different form), mainly for string manipulation and for writing to file descriptors, often using the tools from the first part.
- **Part 3 – Linked lists:** I discovered a new kind of data structure, the linked list, which can grow and shrink one element at a time, without having to know its size in advance or reallocate everything. These functions mostly build on each other, such as `ft_lstmap` relying on `ft_lstnew` and `ft_lstclear`.

## Instructions


## Library description

### Part 1 - Libc functions

- `ft_isalpha`: Returns 1 if the character passed as a parameter is alphabetical (from `'a'` to `'z'` or `'A'` to `'Z'`) in the ASCII table, and 0 otherwise.
- `ft_isdigit`: Returns 1 if the character passed as a parameter is a digit (from `'0'` to `'9'`) in the ASCII table, and 0 otherwise.
- `ft_isalnum`: Returns 1 if the character passed as a parameter is alphabetical or a digit (from `'a'` to `'z'`, from `'A'` to `'Z'` or from `'0'` to `'9'`) in the ASCII table, and 0 otherwise.
- `ft_isascii`: Returns 1 if the value passed as a parameter is a character in the ASCII table (from 0 to 127), and 0 otherwise.
- `ft_isprint`: Returns 1 if the character passed as a parameter is printable (from 32, the space `' '`, to 126, `'~'`) in the ASCII table, and 0 otherwise.
- `ft_strlen`: Returns the number of characters in the string passed as a parameter, counting until the null terminator (`'\0'`), which is not included in the count.
- `ft_memset`: 
