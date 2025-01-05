#include <stdio.h>
#include <iostream>
#include "node.h"
#include "linearLinkedList.h"

/*
linearLinkedList
*/

using namespace std;


int main() {

    nodeHeader* nodeHead; //스택에 저장됨됨

    node* temp; //결과값을 임시 저장할 포인터 생성, 힙에 저장된 node를 가르킴  -  스택에 저장됨.



    nodeHead = makeList(); //리스트 생성하여, nodeHead포인터에 저장

    cout << " 1. 리스트에 [Mon], [Wed], [Sun] 노드 삽입하기! \n";
    insertFirst(nodeHead, "Mon"); //책에서는 insertLast를 이용했지만, 난 first를 이용해서 첫 노드를 만듦,  +  char*이 입력값, 그냥 문자열을 주면 문자열 맨 처음 주소값을 주니 되는 것임임
    insertLast(nodeHead, "Wed");
    insertLast(nodeHead, "Sun");

    printList(nodeHead);

    cout << "\n 2. 리스트에서 [Wed] 노드 탐색하기! \n";
    temp = _searchNode(nodeHead, "Wed");
    if(temp == NULL)    cout << "탐색에 실패하여, 수행하지 못했습니다.\n";
    else    cout << temp -> data << " 를 찾았습니다 \n";

    cout << "\n 3. 리스트의 [Wed] 뒤에 [Fri] 노드 삽입하기! \n";
    insertMiddle(nodeHead, temp, "Fri");
    /*질문
    1. 이렇게 파라미터에 char여러개 값을 넣으면
    힙에 들어가고 인자로 가는건가?
    즉, 정확한 과정이 궁금하다.
    */
   printList(nodeHead);

    cout << "\n 4. 리스트에서 [Sun] 노드 삭제하기! \n";
    temp = _searchNode(nodeHead, "Sun");

    deleteNode(nodeHead, temp);

    printList(nodeHead);




    freeList(nodeHead);
    getchar(); //입력 대기.

    return 0;

}
