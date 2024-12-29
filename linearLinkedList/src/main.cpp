#include <linearLinkedList.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    
    int menuNum = 0; //메뉴 번호 입력을 저장 할 변수 초기화

    nodeHeader* nodeHeader; //노드 헤더를 저장할 (즉, 리스트를 저장할 객체 미리 선언.)

    bool loopStopper = false; //루프문 트리거  true 일때 벗어나짐.


    cout << "번호를 입력하여, 명령을 실행하세요. \n 1. 리스트 생성.\n 2.";

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
        


    case 3:



    default:
        break;
    }

}


