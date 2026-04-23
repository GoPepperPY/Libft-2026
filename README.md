*This project has been created as part of the 42 curriculum by gopiment.*

## Description

**libft** is a custom C library built as part of the 42 Porto curriculum. The goal of this project is to understand how standard C library functions work by reimplementing them from scratch, and to create a personal toolkit of utility functions that can be reused throughout the 42 cursus.

The library covers three areas:
- Re-implementations of standard `libc` functions (e.g. `ft_strlen`, `ft_memcpy`, `ft_atoi`, etc.)
- Additional utility functions for string and memory manipulation not present in the standard library
- Linked list manipulation functions using the `t_list` structure

## Instructions

### Compilation

Clone the repository and compile the library using the provided `Makefile`:

```bash
make
```

This produces the `libft.a` static library at the root of the repository.

### Makefile rules

| Rule | Description |
|------|-------------|
| `make` / `make all` | Compiles the mandatory part into `libft.a` |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Runs `fclean` then `all` |

### Using the library in another project

```bash
cc your_file.c -L. -lft -I. -o your_program
```

Make sure `libft.a` and `libft.h` are at the root of your repository, or adjust the paths accordingly.

## Description of the library

### Part 1 — Libc functions

Reimplementations of standard C library functions. All functions have the same prototype and behaviour as their originals, prefixed with `ft_`.

| Function | Description |
|----------|-------------|
| `ft_isalpha` | Returns 1 if the character is alphabetic, 0 otherwise |
| `ft_isdigit` | Returns 1 if the character is a digit, 0 otherwise |
| `ft_isalnum` | Returns 1 if the character is alphanumeric, 0 otherwise |
| `ft_isascii` | Returns 1 if the character is in the ASCII table, 0 otherwise |
| `ft_isprint` | Returns 1 if the character is printable, 0 otherwise |
| `ft_toupper` | Converts a lowercase letter to uppercase |
| `ft_tolower` | Converts an uppercase letter to lowercase |
| `ft_strlen` | Returns the length of a string |
| `ft_strlcpy` | Copies a string into a size-bounded buffer; returns total length |
| `ft_strlcat` | Appends a string to another in a size-bounded buffer; returns total length |
| `ft_strchr` | Returns a pointer to the first occurrence of a character in a string |
| `ft_strrchr` | Returns a pointer to the last occurrence of a character in a string |
| `ft_strncmp` | Compares two strings up to n characters |
| `ft_strnstr` | Locates a substring in a string, searching at most n characters |
| `ft_strdup` | Allocates memory and returns a duplicate of the given string |
| `ft_memset` | Fills a memory area with a constant byte |
| `ft_bzero` | Sets a memory area to zero |
| `ft_memcpy` | Copies n bytes from one memory area to another (no overlap) |
| `ft_memmove` | Copies n bytes handling overlapping memory areas correctly |
| `ft_memchr` | Scans a memory area for a character, returns a pointer to it |
| `ft_memcmp` | Compares two memory areas byte by byte |
| `ft_atoi` | Converts the initial portion of a string to an integer |
| `ft_calloc` | Allocates zero-initialised memory for an array of elements |

### Part 2 — Additional functions

Utility functions that extend the standard library or do not exist in it.

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Allocates and returns a substring of `s` starting at `start` with max length `len` |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Allocates and returns a new string that is the concatenation of `s1` and `s2` |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Allocates and returns a copy of `s1` with characters in `set` removed from both ends |
| `ft_split` | `char **ft_split(char const *s, char c)` | Allocates and returns a NULL-terminated array of strings obtained by splitting `s` on delimiter `c` |
| `ft_itoa` | `char *ft_itoa(int n)` | Allocates and returns a string representation of the integer `n`; handles negatives |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Applies function `f` to each character of `s` and returns the resulting new string |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies function `f` to each character of `s` in-place, passing its index |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Outputs character `c` to file descriptor `fd` |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Outputs string `s` to file descriptor `fd` |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Outputs string `s` followed by a newline to file descriptor `fd` |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Outputs integer `n` to file descriptor `fd` |

### Part 3 — Linked list functions

Functions to manipulate singly linked lists. The `t_list` structure is defined in `libft.h` as:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| Function | Prototype | Description |
|----------|-----------|-------------|
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | Allocates and returns a new node with `content` set and `next` as NULL |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new)` | Adds node `new` at the beginning of the list |
| `ft_lstsize` | `int ft_lstsize(t_list *lst)` | Returns the number of nodes in the list |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Returns the last node of the list |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new)` | Adds node `new` at the end of the list |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees the content of `lst` using `del`, then frees the node (does not free the next node) |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Deletes and frees all nodes in the list using `del`, then sets the pointer to NULL |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies function `f` to the content of each node in the list |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Applies `f` to each node's content and builds a new list; uses `del` on failure |

## Resources

- [The C Programming Language – Kernighan & Ritchie](https://en.wikipedia.org/wiki/The_C_Programming_Language) — reference for standard C behaviour and function specifications
- [cppreference.com — C standard library](https://en.cppreference.com/w/c) — used to verify the exact prototype and behaviour of each function
- [man7.org — Linux man pages](https://www.man7.org/linux/man-pages/) — primary reference for matching expected behaviour and edge cases of each reimplemented function
- [42 Docs — libft](https://harm-smits.github.io/42docs/projects/libft) — community documentation for the project structure and requirements

**AI usage:** AI was not used in any part of this project — neither for writing code, understanding concepts, nor any other task.
