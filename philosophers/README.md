# 📚 philosophers

## 📖 About
- `philosophers` 프로젝트는 고전적인 동시성 문제인 “식사하는 철학자 문제”를 구현하는 과제입니다.  
- 여러 철학자가 동시에 포크를 집으려 할 때 발생하는 **교착 상태(Deadlock)** 및 **경쟁 조건(Race Condition)** 문제를 다루며,  
- POSIX 스레드(pthread)와 뮤텍스(Mutex)를 사용해 동기화와 자원 관리를 직접 구현합니다.
- 보너스의 경우 프로세스와 세마포어를 사용해 자원을 관리합니다.

---

## Review
- 멀티스레드 / 멀티 프로세스 환경에서 공유 자원인 포크를 어떻게 안전하게 접근할지 고민하는 과정이 인상적이었다.  
- 뮤텍스 / 세마포어를 적절히 사용해 교착 상태를 방지하며, 철학자들이 일정 시간 안에 식사를 완료하도록 로직을 구성하는 것이 어렵지만 의미 있었다.  
- 상태 관리와 타이밍 제어가 중요했고, 세밀한 디버깅과 테스트가 프로젝트 완성도를 좌우했다.  
- 실시간성과 병행성 개념에 대한 이해도를 높이는 좋은 경험이었다.
- 개인적으로 try_lock 방식을 직접 구현하여 데드락을 방지했다.

---

## 🏁 Run & Test
### 빌드
```
make
```

### 실행 예시
```
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- 인자 설명:  
  - `number_of_philosophers` : 철학자 수  
  - `time_to_die` : 철학자가 죽기 전까지 시간을 밀리초로 지정  
  - `time_to_eat` : 식사하는 시간 (밀리초)  
  - `time_to_sleep` : 잠자는 시간 (밀리초)  
  - `[number_of_times_each_philosopher_must_eat]` : 선택적, 각 철학자가 최소 몇 번 식사해야 하는지  

---

## ⚙️ Implementation Details
- **스레드 생성 및 관리**  
  - 각 철학자마다 하나의 스레드를 생성하여 독립 동작  
- **뮤텍스 이용 포크 접근 제어**  
  - 각 포크마다 뮤텍스를 배치하여 동시에 한 철학자만 들 수 있도록 제한  
- **교착 상태 방지 전략**  
  - 철학자마다 포크 집는 순서를 조정하거나, 짝수/홀수로 나누어 우선순위 차등 부여  
- **타이밍 관리**  
  - 밀리초 단위 시간 측정 함수를 활용해 `time_to_die`, `time_to_eat`, `time_to_sleep` 구현  
- **상태 출력**  
  - 각 상태 변화(먹기, 잠자기, 생각하기) 시 적절한 로그 출력  

---

## 🧑🏻‍💻 Author
- **sangshin** (42Seoul cadet)  
