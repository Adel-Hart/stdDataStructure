#include <linearLinkedList.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int menuNum = 0; //메뉴 번호 입력을 저장 할 변수 초기화

    nodeHeader* nodeHeader; //노드 헤더를 저장할 (즉, 리스트를 저장할 객체 미리 선언.)

    bool loopStopper = false; //루프문 트리거  true 일때 벗어나짐.


    cout << "번호를 입력하여, 명령을 실행하세요.  ! 입력이 필요한 메뉴는 번호앞에 언더바로 구분합니다. \n 1. 리스트 생성.\n _2. 첫번째에 노드 삽입.\n _3. 중간에 노드 삽입.\n _4. 마지막에 노드 삽입.\n 5. 리스트 출력하기.\n _6. 노드 삭제하기.\n 7. 리스트 전체 삭제하기.\n";

    cin >> menuNum; //입력

    switch (menuNum)
    {
    case 1:

        nodeHeader = makeList(); //리스트 생성.

        if(nodeHeader == NULL || nodeHeader == nullptr){

            cout << "리스트 생성에서 오류가 발생하였습니다. 명령을 수행하지 못 했습니다. \n";

        }
        break;
    
    case 2:
        
        {
            char tempInput[10]; //data는 총 10까지 하기로 node.h에서 선언.

            cout << "맨 앞 노드에 저장 할 값을 문자열로 입력해 주세요 \n";
            cin >> tempInput;

            insertFirst(nodeHeader, tempInput); //tempInput 즉, 문자배열은, 그냥 쓰면 배열[0]의 주소를 의미
            
            cout << "삽입 완료 \n";

        } //스택변수 자연 초기화 하려고, 이렇게 scope 설정함.


        break;

    case 3:
        {
            char tempInput[10]; //data는 총 10까지 하기로 node.h에서 선언.

            cout << "중간 노드에 저장 할 값을 문자열로 입력해 주세요 \n";
            cin >> tempInput;

            insertMiddle(nodeHeader, tempInput); //tempInput 즉, 문자배열은, 그냥 쓰면 배열[0]의 주소를 의미
            
            cout << "삽입 완료 \n";

        } //스택변수 자연 초기화 하려고, 이렇게 scope 설정함.


        break;

    case 4:
        {
            char tempInput[10]; //data는 총 10까지 하기로 node.h에서 선언.

            cout << "마지막 노드에 저장 할 값을 문자열로 입력해 주세요 \n";
            cin >> tempInput;

            insertLast(nodeHeader, tempInput); //tempInput 즉, 문자배열은, 그냥 쓰면 배열[0]의 주소를 의미
            
            cout << "삽입 완료 \n";

        } //스택변수 자연 초기화 하려고, 이렇게 scope 설정함.


        break;


    case 5:
    
        printList(nodeHeader); //리스트 출력하는 함수,

        cout << "\n end \n";

        break;


    default:
        break;
    }

}


