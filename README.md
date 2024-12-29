
 공부할 것
 1. makefile
 

 새로 얻은 지식
 1. typedef struct 이름 {} 선언 의 역할 및 왜 하는지 (node.h)
 2. typedef struct 구문 내에서, 자기 자신의 포인터를 호출 할 때 굳이 앞에 struct를 붙이는 이유 (node.h)
 3. 헤더파일에서 선언된 함수 ( 다른 파일과 공유 하는 함수 )의 내용 추가 및 변경이 컴파일 되는 이유 (linearLinkedList.cpp)
 4. MAKEFILE
 5. 익명 구조체 (node.h)
 6. 화살표 연산자에 대하여 (linearLinkedList.cpp)
 7. 얕은복사(그냥 등호 사용)와 깊은복사(strcpy or memcpy 사용), 그리고 얕은복사시 delete 의 작동 (linearLinkedList.cpp)
 8. 


 할 것
 1. 해당 연결 리스트, 인덱스 기능 추가해 보기.
 2. 스마트 포인터 사용해보기


 개선점
 1. while 문 루프 로직 개선
    - while( temp -> link != NULL) 인데, temp 는 NULL 이 될수도 있음을 이용하여
    while(temp != NULL) 하면 된다.
    이러면 괜히 끝을 예외 처리 할 필요 없음.


 2. https://velog.io/@tosspayments/null-%EB%A6%AC%ED%84%B4%EC%9D%80-%EC%99%9C-%EB%82%98%EC%81%A0%EA%B9%8C


 궁금점
 1. (node*) 이렇게 강제 형변환, 나중에 ㄱㅊ은걸까?
 2. 책에서는 node delete함수를 재귀가 아니라, 다른 로직으로 했는데 속도 차이?




 표기법
 1. ver1,2 -> 직접 검토
    ver3 -> chatGpt 검토.