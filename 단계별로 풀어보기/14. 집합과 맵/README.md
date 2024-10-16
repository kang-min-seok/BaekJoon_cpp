# 집합과 맵

## map 특징
```cpp
#include <map>
map<string, string> N;
```

- key-value형태
- key값으로 탐색 / 수정 등을 할 수 있음
- 중복된 key값을 허용하지 않음
- key는 자동으로 정렬되어 저장됨

## unordered_map 특징
```cpp
#include <unordered_map>
unordered_map<string, string> N;
```

- map과 거의 유사하지만 key가 자동 정렬 안됨
- map보다 더 효율적이기 떄문에 key자동 정렬 필요 없으면 이게 적합

## set 특징
```cpp
#include <set>
set<string> N;
```

- key만 존재하는 형태
- key값으로 탐색 / 수정 등을 할 수 있음
- 중복된 key값을 허용하지 않음
- key는 자동으로 정렬되어 저장됨

## unordered_set 특징
```cpp
#include <unordered_set>
unordered_set<string> N;
```

- set와 거의 유사하지만 key가 자동정렬이 안됨
- set보다 더 효율적이기 떄문에 key자동 정렬 필요 없으면 이게 적합