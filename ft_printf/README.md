# 📚 ft_printf

## 📖 About
- `ft_printf`는 C의 표준 입출력 함수 `printf`를 직접 구현하는 프로젝트입니다.  
- 단순한 문자열 출력이 아니라, **포맷팅 문자열(format string)과 가변 인자(variadic arguments)를 처리**하는 기능을 다룹니다.  
- 과제를 통해 **가변 인자 처리 방식(va_list, va_start, va_arg, va_end)**, 문자열 파싱, 출력 형식 제어에 대해 학습할 수 있습니다.  

---

## 📝 Review
- 이 프로젝트는 단순한 함수 구현을 넘어 **"문자열 파서를 직접 만드는 경험"** 을 할 수 있었다.  
- `%c, %s, %p, %d, %i, %u, %x, %X` 같은 포맷 문자를 처리하면서, 데이터 타입과 출력 형태를 직접 제어하는 과정을 몸소 실습할 수 있었다.  
- 가장 큰 도전 과제는:  
  1. **가변 인자(variadic arguments)** 를 어떻게 안전하게 꺼내 쓸 것인가  
  2. **출력 버퍼 관리**와 **에러 처리**  
  3. `%p` 포인터 출력 시 주소값(16진수) 처리와 일관된 formatting 맞추기  
- 완성 후에 기존 libc의 `printf`와 비교해 다양한 테스트 케이스를 통과했을 때 뿌듯했다.  

---

## 🏁 Run & Test
### Compile
```
cc -Wall -Wextra -Werror ft_printf.c *.c -o ft_printf
```

### Usage Example
```
ft_printf("Hello %s! You are %d years old.\n", "world", 42);
```

👉 출력:
```
Hello world! You are 42 years old.
```

### Test 
- 기본 Spec 테스트 완료 ✅  
- [tripouille/printfTester](https://github.com/Tripouille/printfTester) 로 추가 검증 ✅  

---

## ⚙️ Implementation Details
- **가변 인자 처리 (Variadic Functions)**  
  - `<stdarg.h>` 의 `va_list`, `va_start`, `va_arg`, `va_end`를 사용해 인자를 순차적으로 꺼냄.  
- **포맷 문자열 파싱**  
  - `%`로 시작하는 토큰을 인식 후, 해당되는 변환자(c, s, p, d, i, u, x, X) 처리.  
- **출력 관리**  
  - 매 호출마다 `write(1, &c, 1)` 등을 이용해 결과 출력.  
  - 총 출력된 문자의 수를 리턴해야 함 (printf와 동일한 동작 보장).  
- **예외 처리 & 확장성**  
  - `%` 뒤에 잘못된 포맷 문자가 올 경우, 그대로 출력하게 구현.  
  - 보너스로 `%%` → `%` 출력 지원.  

---

## 🧑🏻‍💻 Author
- **sangshin** (42Seoul cadet)  
