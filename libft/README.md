# 📚 libft
@42Seoul : (2023.XX.XX ~ 2023.XX.XX)  

---

## 📖 About
- `libft`는 C 언어 학습의 출발점으로, C 표준 라이브러리의 필수 함수들을 직접 구현해보는 프로젝트입니다.  
- 앞으로 진행할 모든 42 과제의 기반이 되는 **개인 맞춤형 C 라이브러리**를 제작하는 것이 목표입니다.  

구현 항목:
- [Libc Functions](#📕-libc-functions-standard-c-library) : `<ctype.h>`, `<string.h>`, `<stdlib.h>`
- [Additional Functions](#📗-additional-functions) : split, strjoin, itoa 등
- [Linked List Functions](#📘-linked-list) : 단일 연결 리스트 구현

---

## 📝 Review
### Libc 함수를 작성하는 과제
- 크게 3가지를 배울 수 있는 과제였다.
 1. C 표준 라이브러리에서 제공하는 함수들의 존재와 역할을 이해하게 되었다.
 2. man page를 레퍼런스 삼아 공부하는 방법을 배웠다.
 3. 정적 라이브러리를 만들고 사용하는 방법을 배웠다.

- c에서 문자열과 포인터를 생각없이 조작하는게 얼마나 위험할 수 있는지 느꼈다..
---

## 🏁 Run

```sh
make
make bonus
nm libft.a
```

## 📕 Libc Functions (Standard C Library)
- C 표준 라이브러리 함수 재구현

| Category | Functions |
|:--------:|:----------|
| `<string.h>` - memory | `memset`, `memcpy`, `memccpy`, `memmove`, `memchr`, `memcmp` |
| `<string.h>` - string | `strlen`, `strlcpy`, `strlcat`, `strchr`, `strrchr`, `strnstr`, `strncmp`, `strdup` |
| `<stdlib.h>` | `calloc`, `atoi` |
| `<ctype.h>` | `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`, `toupper`, `tolower` |

---

## 📗 Additional Functions
- 실제 개발 과정에서 편리하게 사용할 수 있는 보조 함수들  

| Type | Function | Description |
|:----:|:---------|:------------|
| `string` | `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi` | 문자열 처리 & 변환 |
| `output` | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | fd 기반 출력 |

---

## 📘 Linked List Functions
- 단순 연결 리스트 구조를 지원하는 함수  

| Function | Description |
|----------|-------------|
| `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back` | 노드 생성 & 삽입 |
| `ft_lstsize`, `ft_lstlast` | 리스트 탐색 |
| `ft_lstdelone`, `ft_lstclear` | 노드/리스트 해제 |
| `ft_lstiter`, `ft_lstmap` | 반복 & 새로운 리스트 생성 |

---

## 🧑🏻‍💻 Author
- **sangshin** (42Seoul cadet)  
