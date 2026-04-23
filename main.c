#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ========== KO TRACKER ========== */

#define MAX_KO 256

static char	*g_ko_list[MAX_KO];
static int	g_ko_count = 0;
static int	g_total = 0;

static void	print_header(const char *title)
{
	printf("\n");
	printf("==================================================\n");
	printf("  %s\n", title);
	printf("==================================================\n");
}

static void	print_test(const char *name, int passed)
{
	g_total++;
	if (passed)
	{
		printf("  [OK]  %s\n", name);
	}
	else
	{
		printf("  [KO]  %s\n", name);
		if (g_ko_count < MAX_KO)
			g_ko_list[g_ko_count++] = (char *)name;
	}
}

/* ========== PART 1 — LIBC FUNCTIONS ========== */

static void	test_isalpha(void)
{
	print_header("ft_isalpha");
	print_test("ft_isalpha('a') == 1", ft_isalpha('a') == 1);
	print_test("ft_isalpha('Z') == 1", ft_isalpha('Z') == 1);
	print_test("ft_isalpha('1') == 0", ft_isalpha('1') == 0);
	print_test("ft_isalpha(' ') == 0", ft_isalpha(' ') == 0);
}

static void	test_isdigit(void)
{
	print_header("ft_isdigit");
	print_test("ft_isdigit('0') == 1", ft_isdigit('0') == 1);
	print_test("ft_isdigit('9') == 1", ft_isdigit('9') == 1);
	print_test("ft_isdigit('a') == 0", ft_isdigit('a') == 0);
	print_test("ft_isdigit(' ') == 0", ft_isdigit(' ') == 0);
}

static void	test_isalnum(void)
{
	print_header("ft_isalnum");
	print_test("ft_isalnum('a') == 1", ft_isalnum('a') == 1);
	print_test("ft_isalnum('5') == 1", ft_isalnum('5') == 1);
	print_test("ft_isalnum('!') == 0", ft_isalnum('!') == 0);
}

static void	test_isascii(void)
{
	print_header("ft_isascii");
	print_test("ft_isascii(0)   == 1", ft_isascii(0) == 1);
	print_test("ft_isascii(127) == 1", ft_isascii(127) == 1);
	print_test("ft_isascii(128) == 0", ft_isascii(128) == 0);
	print_test("ft_isascii(-1)  == 0", ft_isascii(-1) == 0);
}

static void	test_isprint(void)
{
	print_header("ft_isprint");
	print_test("ft_isprint(' ')  == 1", ft_isprint(' ') == 1);
	print_test("ft_isprint('~')  == 1", ft_isprint('~') == 1);
	print_test("ft_isprint('\n') == 0", ft_isprint('\n') == 0);
	print_test("ft_isprint(31)   == 0", ft_isprint(31) == 0);
}

static void	test_strlen(void)
{
	print_header("ft_strlen");
	print_test("ft_strlen(\"hello\") == 5", ft_strlen("hello") == 5);
	print_test("ft_strlen(\"\")      == 0", ft_strlen("") == 0);
	print_test("ft_strlen(\"42\")    == 2", ft_strlen("42") == 2);
}

static void	test_memset(void)
{
	char	buf[6];

	print_header("ft_memset");
	ft_memset(buf, 'A', 5);
	buf[5] = '\0';
	print_test("ft_memset fills 5 bytes with 'A'", strcmp(buf, "AAAAA") == 0);
	ft_memset(buf, 0, 5);
	print_test("ft_memset fills 5 bytes with 0", buf[0] == 0 && buf[4] == 0);
}

static void	test_bzero(void)
{
	char	buf[5];

	print_header("ft_bzero");
	memset(buf, 'X', 5);
	ft_bzero(buf, 5);
	print_test("ft_bzero zeroes 5 bytes", buf[0] == 0 && buf[4] == 0);
}

static void	test_memcpy(void)
{
	char	dst[10];

	print_header("ft_memcpy");
	ft_memcpy(dst, "hello", 6);
	print_test("ft_memcpy copies \"hello\"", strcmp(dst, "hello") == 0);
}

static void	test_memmove(void)
{
	char	buf[10] = "hello";

	print_header("ft_memmove");
	ft_memmove(buf + 1, buf, 5);
	print_test("ft_memmove overlapping copy", strcmp(buf + 1, "hello") == 0);
}

static void	test_strlcpy(void)
{
	char	dst[10];
	size_t	ret;

	print_header("ft_strlcpy");
	ret = ft_strlcpy(dst, "hello", sizeof(dst));
	print_test("ft_strlcpy copies correctly", strcmp(dst, "hello") == 0);
	print_test("ft_strlcpy returns src length (5)", ret == 5);
	ret = ft_strlcpy(dst, "hello", 3);
	print_test("ft_strlcpy truncates to size-1", strcmp(dst, "he") == 0);
}

static void	test_strlcat(void)
{
	char	dst[10] = "he";
	size_t	ret;

	print_header("ft_strlcat");
	ret = ft_strlcat(dst, "llo", sizeof(dst));
	print_test("ft_strlcat appends correctly", strcmp(dst, "hello") == 0);
	print_test("ft_strlcat returns total length (5)", ret == 5);
}

static void	test_toupper(void)
{
	print_header("ft_toupper");
	print_test("ft_toupper('a') == 'A'", ft_toupper('a') == 'A');
	print_test("ft_toupper('z') == 'Z'", ft_toupper('z') == 'Z');
	print_test("ft_toupper('A') == 'A'", ft_toupper('A') == 'A');
	print_test("ft_toupper('1') == '1'", ft_toupper('1') == '1');
}

static void	test_tolower(void)
{
	print_header("ft_tolower");
	print_test("ft_tolower('A') == 'a'", ft_tolower('A') == 'a');
	print_test("ft_tolower('Z') == 'z'", ft_tolower('Z') == 'z');
	print_test("ft_tolower('a') == 'a'", ft_tolower('a') == 'a');
	print_test("ft_tolower('1') == '1'", ft_tolower('1') == '1');
}

static void	test_strchr(void)
{
	const char	*s = "hello";

	print_header("ft_strchr");
	print_test("ft_strchr finds 'e'", ft_strchr(s, 'e') == s + 1);
	print_test("ft_strchr finds '\\0'", ft_strchr(s, '\0') == s + 5);
	print_test("ft_strchr returns NULL if not found", ft_strchr(s, 'z') == NULL);
}

static void	test_strrchr(void)
{
	const char	*s = "hello";

	print_header("ft_strrchr");
	print_test("ft_strrchr finds last 'l'", ft_strrchr(s, 'l') == s + 3);
	print_test("ft_strrchr returns NULL if not found", ft_strrchr(s, 'z') == NULL);
}

static void	test_strncmp(void)
{
	print_header("ft_strncmp");
	print_test("ft_strncmp equal strings == 0", ft_strncmp("abc", "abc", 3) == 0);
	print_test("ft_strncmp \"abc\" > \"abb\"", ft_strncmp("abc", "abb", 3) > 0);
	print_test("ft_strncmp \"abb\" < \"abc\"", ft_strncmp("abb", "abc", 3) < 0);
	print_test("ft_strncmp n=0 == 0", ft_strncmp("abc", "xyz", 0) == 0);
}

static void	test_memchr(void)
{
	const char	*s = "hello";

	print_header("ft_memchr");
	print_test("ft_memchr finds 'e'", ft_memchr(s, 'e', 5) == s + 1);
	print_test("ft_memchr returns NULL if not found", ft_memchr(s, 'z', 5) == NULL);
}

static void	test_memcmp(void)
{
	print_header("ft_memcmp");
	print_test("ft_memcmp equal == 0", ft_memcmp("abc", "abc", 3) == 0);
	print_test("ft_memcmp \"abc\" > \"abb\"", ft_memcmp("abc", "abb", 3) > 0);
	print_test("ft_memcmp n=0 == 0", ft_memcmp("abc", "xyz", 0) == 0);
}

static void	test_strnstr(void)
{
	print_header("ft_strnstr");
	print_test("ft_strnstr finds needle", ft_strnstr("hello world", "world", 11) != NULL);
	print_test("ft_strnstr out of len returns NULL", ft_strnstr("hello world", "world", 5) == NULL);
	print_test("ft_strnstr empty needle returns haystack", ft_strnstr("hello", "", 5) != NULL);
}

static void	test_atoi(void)
{
	print_header("ft_atoi");
	print_test("ft_atoi(\"42\")    == 42",  ft_atoi("42") == 42);
	print_test("ft_atoi(\"-42\")   == -42", ft_atoi("-42") == -42);
	print_test("ft_atoi(\"  21\")  == 21",  ft_atoi("  21") == 21);
	print_test("ft_atoi(\"0\")     == 0",   ft_atoi("0") == 0);
	print_test("ft_atoi(\"abc\")   == 0",   ft_atoi("abc") == 0);
}

static void	test_calloc(void)
{
	int	*arr;

	print_header("ft_calloc");
	arr = (int *)ft_calloc(5, sizeof(int));
	print_test("ft_calloc returns non-NULL", arr != NULL);
	print_test("ft_calloc zeroes memory", arr[0] == 0 && arr[4] == 0);
	free(arr);
	arr = (int *)ft_calloc(0, sizeof(int));
	print_test("ft_calloc(0, ...) returns non-NULL freeable ptr", arr != NULL);
	free(arr);
}

static void	test_strdup(void)
{
	char	*dup;

	print_header("ft_strdup");
	dup = ft_strdup("hello");
	print_test("ft_strdup returns non-NULL", dup != NULL);
	print_test("ft_strdup content matches", strcmp(dup, "hello") == 0);
	free(dup);
}

/* ========== PART 2 — ADDITIONAL FUNCTIONS ========== */

static void	test_substr(void)
{
	char	*s;

	print_header("ft_substr");
	s = ft_substr("hello world", 6, 5);
	print_test("ft_substr extracts \"world\"", s && strcmp(s, "world") == 0);
	free(s);
	s = ft_substr("hello", 10, 5);
	print_test("ft_substr start > len returns \"\"", s && strcmp(s, "") == 0);
	free(s);
	s = ft_substr("hello", 0, 3);
	print_test("ft_substr len limit to 3 gives \"hel\"", s && strcmp(s, "hel") == 0);
	free(s);
}

static void	test_strjoin(void)
{
	char	*s;

	print_header("ft_strjoin");
	s = ft_strjoin("hello", " world");
	print_test("ft_strjoin \"hello\" + \" world\"", s && strcmp(s, "hello world") == 0);
	free(s);
	s = ft_strjoin("", "42");
	print_test("ft_strjoin \"\" + \"42\" == \"42\"", s && strcmp(s, "42") == 0);
	free(s);
}

static void	test_strtrim(void)
{
	char	*s;

	print_header("ft_strtrim");
	s = ft_strtrim("  hello  ", " ");
	print_test("ft_strtrim trims spaces", s && strcmp(s, "hello") == 0);
	free(s);
	s = ft_strtrim("xxhelloxx", "x");
	print_test("ft_strtrim trims 'x'", s && strcmp(s, "hello") == 0);
	free(s);
	s = ft_strtrim("hello", "");
	print_test("ft_strtrim empty set returns unchanged", s && strcmp(s, "hello") == 0);
	free(s);
}

static void	test_split(void)
{
	char	**arr;

	print_header("ft_split");
	arr = ft_split("hello world 42", ' ');
	print_test("ft_split returns non-NULL", arr != NULL);
	print_test("ft_split [0] == \"hello\"", arr && strcmp(arr[0], "hello") == 0);
	print_test("ft_split [1] == \"world\"", arr && strcmp(arr[1], "world") == 0);
	print_test("ft_split [2] == \"42\"",    arr && strcmp(arr[2], "42") == 0);
	print_test("ft_split [3] == NULL",      arr && arr[3] == NULL);
	if (arr)
	{
		int	i = 0;
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
	arr = ft_split("", ' ');
	print_test("ft_split empty string gives [NULL]", arr && arr[0] == NULL);
	free(arr);
}

static void	test_itoa(void)
{
	char	*s;

	print_header("ft_itoa");
	s = ft_itoa(42);
	print_test("ft_itoa(42)      == \"42\"",          s && strcmp(s, "42") == 0);
	free(s);
	s = ft_itoa(-42);
	print_test("ft_itoa(-42)     == \"-42\"",         s && strcmp(s, "-42") == 0);
	free(s);
	s = ft_itoa(0);
	print_test("ft_itoa(0)       == \"0\"",           s && strcmp(s, "0") == 0);
	free(s);
	s = ft_itoa(-2147483648);
	print_test("ft_itoa(INT_MIN) == \"-2147483648\"", s && strcmp(s, "-2147483648") == 0);
	free(s);
}

static char	add_one(unsigned int i, char c)
{
	(void)i;
	return (c + 1);
}

static void	test_strmapi(void)
{
	char	*s;

	print_header("ft_strmapi");
	s = ft_strmapi("abc", add_one);
	print_test("ft_strmapi applies f to each char", s && strcmp(s, "bcd") == 0);
	free(s);
}

static void	increment(unsigned int i, char *c)
{
	(void)i;
	(*c)++;
}

static void	test_striteri(void)
{
	char	s[] = "abc";

	print_header("ft_striteri");
	ft_striteri(s, increment);
	print_test("ft_striteri modifies string in-place", strcmp(s, "bcd") == 0);
}

static void	test_putchar_fd(void)
{
	print_header("ft_putchar_fd");
	printf("  ft_putchar_fd('A', 1): ");
	ft_putchar_fd('A', 1);
	printf("\n");
	printf("  [VISUAL] Check 'A' printed above\n");
}

static void	test_putstr_fd(void)
{
	print_header("ft_putstr_fd");
	printf("  ft_putstr_fd(\"hello\", 1): ");
	ft_putstr_fd("hello", 1);
	printf("\n");
	printf("  [VISUAL] Check 'hello' printed above\n");
}

static void	test_putendl_fd(void)
{
	print_header("ft_putendl_fd");
	printf("  ft_putendl_fd(\"hello\", 1): ");
	ft_putendl_fd("hello", 1);
	printf("  [VISUAL] Check 'hello\\n' printed above\n");
}

static void	test_putnbr_fd(void)
{
	print_header("ft_putnbr_fd");
	printf("  ft_putnbr_fd(42, 1): ");
	ft_putnbr_fd(42, 1);
	printf("\n");
	printf("  ft_putnbr_fd(-42, 1): ");
	ft_putnbr_fd(-42, 1);
	printf("\n");
	printf("  [VISUAL] Check '42' and '-42' printed above\n");
}

/* ========== PART 3 — LINKED LIST ========== */

static void	test_lstnew(void)
{
	t_list	*node;

	print_header("ft_lstnew");
	node = ft_lstnew("hello");
	print_test("ft_lstnew returns non-NULL", node != NULL);
	print_test("ft_lstnew content set correctly", node && strcmp((char *)node->content, "hello") == 0);
	print_test("ft_lstnew next is NULL", node && node->next == NULL);
	free(node);
}

static void	test_lstadd_front(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;

	print_header("ft_lstadd_front");
	node1 = ft_lstnew("first");
	node2 = ft_lstnew("second");
	lst = node1;
	ft_lstadd_front(&lst, node2);
	print_test("ft_lstadd_front: new node is at front", lst == node2);
	print_test("ft_lstadd_front: next points to old head", lst->next == node1);
	free(node1);
	free(node2);
}

static void	test_lstsize(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	print_header("ft_lstsize");
	n1 = ft_lstnew("a");
	n2 = ft_lstnew("b");
	n3 = ft_lstnew("c");
	lst = n1;
	n1->next = n2;
	n2->next = n3;
	print_test("ft_lstsize returns 3", ft_lstsize(lst) == 3);
	print_test("ft_lstsize of NULL returns 0", ft_lstsize(NULL) == 0);
	free(n1);
	free(n2);
	free(n3);
}

static void	test_lstlast(void)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	print_header("ft_lstlast");
	n1 = ft_lstnew("a");
	n2 = ft_lstnew("b");
	n3 = ft_lstnew("c");
	n1->next = n2;
	n2->next = n3;
	print_test("ft_lstlast returns last node", ft_lstlast(n1) == n3);
	print_test("ft_lstlast of single node returns itself", ft_lstlast(n3) == n3);
	free(n1);
	free(n2);
	free(n3);
}

static void	test_lstadd_back(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;

	print_header("ft_lstadd_back");
	n1 = ft_lstnew("first");
	n2 = ft_lstnew("second");
	lst = n1;
	ft_lstadd_back(&lst, n2);
	print_test("ft_lstadd_back: head unchanged", lst == n1);
	print_test("ft_lstadd_back: last is n2", ft_lstlast(lst) == n2);
	free(n1);
	free(n2);
}

static void	del_content(void *content)
{
	(void)content;
}

static void	test_lstdelone(void)
{
	t_list	*node;

	print_header("ft_lstdelone");
	node = ft_lstnew("hello");
	ft_lstdelone(node, del_content);
	print_test("ft_lstdelone does not crash", 1);
}

static void	test_lstclear(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	print_header("ft_lstclear");
	n1 = ft_lstnew("a");
	n2 = ft_lstnew("b");
	n3 = ft_lstnew("c");
	lst = n1;
	n1->next = n2;
	n2->next = n3;
	ft_lstclear(&lst, del_content);
	print_test("ft_lstclear sets list to NULL", lst == NULL);
}

static void	iter_fn(void *content)
{
	(void)content;
}

static void	test_lstiter(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;

	print_header("ft_lstiter");
	n1 = ft_lstnew("a");
	n2 = ft_lstnew("b");
	lst = n1;
	n1->next = n2;
	ft_lstiter(lst, iter_fn);
	print_test("ft_lstiter does not crash", 1);
	free(n1);
	free(n2);
}

static void	*map_fn(void *content)
{
	return (ft_strdup((char *)content));
}

static void	test_lstmap(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*n1;
	t_list	*n2;

	print_header("ft_lstmap");
	n1 = ft_lstnew("hello");
	n2 = ft_lstnew("world");
	lst = n1;
	n1->next = n2;
	new = ft_lstmap(lst, map_fn, del_content);
	print_test("ft_lstmap returns non-NULL", new != NULL);
	print_test("ft_lstmap [0] content matches", new && strcmp((char *)new->content, "hello") == 0);
	print_test("ft_lstmap [1] content matches", new && new->next && strcmp((char *)new->next->content, "world") == 0);
	ft_lstclear(&new, free);
	free(n1);
	free(n2);
}

/* ========== SUMMARY ========== */

static void	print_summary(void)
{
	int	passed;
	int	i;

	passed = g_total - g_ko_count;
	printf("\n");
	printf("##################################################\n");
	printf("##                  SUMMARY                    ##\n");
	printf("##################################################\n");
	printf("\n");
	printf("  Total  : %d\n", g_total);
	printf("  Passed : %d\n", passed);
	printf("  Failed : %d\n", g_ko_count);
	printf("\n");
	if (g_ko_count == 0)
	{
		printf("  All tests passed! \n");
	}
	else
	{
		printf("  Failed tests:\n");
		printf("  ------------------------------------------\n");
		i = 0;
		while (i < g_ko_count)
		{
			printf("  [KO]  %s\n", g_ko_list[i]);
			i++;
		}
		printf("  ------------------------------------------\n");
	}
	printf("\n");
}

/* ========== MAIN ========== */

int	main(void)
{
	printf("\n");
	printf("##################################################\n");
	printf("##         LIBFT - FULL TEST SUITE             ##\n");
	printf("##################################################\n");

	printf("\n>>> PART 1 - LIBC FUNCTIONS\n");
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	test_calloc();
	test_strdup();

	printf("\n>>> PART 2 - ADDITIONAL FUNCTIONS\n");
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	test_strmapi();
	test_striteri();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();

	printf("\n>>> PART 3 - LINKED LIST\n");
	test_lstnew();
	test_lstadd_front();
	test_lstsize();
	test_lstlast();
	test_lstadd_back();
	test_lstdelone();
	test_lstclear();
	test_lstiter();
	test_lstmap();

	print_summary();
	return (g_ko_count > 0 ? 1 : 0);
}