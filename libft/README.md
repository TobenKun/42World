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
- 기본적으로 이미 제공되는 Libc 함수들을 굳이 왜 다시 구현할까 의문이 들었지만,  
  **함수의 내부 동작 원리를 파악**하고, **포인터 연산 / 메모리 관리 / 문자열 처리**에 대한 이해를 심화할 수 있었다.  
- 특히 split, strjoin 같은 편의 함수들을 직접 구현하면서 "C에서 문자열을 다루는 것"의 고충과 재미를 동시에 느꼈다.  
- GNU Libc와 성능 비교를 해본 결과, 당연히 최적화 단계에서는 넘을 수 없었지만, **직접 만든 함수가 실제로 운영체제의 함수와 동일하게 동작하는 순간의 성취감**이 남는다.  

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
