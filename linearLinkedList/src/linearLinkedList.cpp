/*
linearLinkedList.h에 있는 함수 내용을 작성함


linearLinkedList.cpp와, main.cpp는 linearLinkedList.h를 같이 include한 것 외에 연관이 없는데,
main.cpp를 실행하면, linarLinkedList.cpp도 실행되는 이유?

-> 컴파일러의 링커 때문에 ** 같은 프로젝트 내에 잇다면 ** 컴파일 할 때, 해당 함수에 대한 정의를
찾고, 해당 함수 정의가 있는 파일 또한 컴파일 함.


블로그 인용 : [ 링킹 과정에서 특정한 소스 파일에 있는 함수들이 어디어디에 있는지 찾는 과정을 거치게 되는데 ]

*/
#include "node.h"
#include "linearLinkedList.h"

#include <stdio.h>
#include <cstring>
#include <iostream>

using namespace std;

nodeHeader *makeList()
{

    nodeHeader *header = new nodeHeader();
    header->head = NULL; // 초기는 값이 비었음(NULL), 리스트만 생성 된 것

    return header;
};

void insertFirst(nodeHeader *header, char *insertData)
{

    node *newNode = new node();

    strncpy_s(newNode->data, sizeof(newNode->data), insertData, sizeof(newNode->data) - 1);
    // 새로운 노드에 데이터 추가, 두 네번째 인자에 각 사이즈가 들어가므로, 복사하는 값을 최대값보다 -1 하여 마지막 \0을 유지함
    // char* insertData 인 이유, char insertData == insertData[0]라서, char[]이 아닌 char임

    if (header->head == NULL)
    { // 리스트가 비었을때(처음에 넣기)

        newNode->link = NULL; // 첫 노드 다음이 없기에(리스트가 비어서) NULL

        header->head = newNode; // 리스트 시작 포인터를 새로만든(newNode)것으로 연결
    }
    else
    { // 리스트가 이미 있을 때 (처음 껄 바꿔 치기)

        newNode->link = header->head; // 원래 첫 노드를 가르키기

        header->head = newNode; // 자기 가르키게 하기.
    }

    return;
};

void insertMiddle(nodeHeader *header, node *pre, char *insertData)
{

    node *newNode = new node();

    strncpy_s(newNode->data, sizeof(newNode->data), insertData, sizeof(newNode->data) - 1);

    if (header->head == NULL)
    { // 빈 리스트 일 경우(자기가 처음이 되야함)

        header->head = newNode;
        newNode->link = NULL;
    }
    else if (pre->link == NULL)
    { // 마지막에 넣는 경우

        pre->link = newNode;
        newNode->link = NULL;
    }
    else
    { // 정상적인 경우 (딱 정 중앙에 넣는 경우)

        newNode->link = pre->link; // 이전 노드가 가르키는 링크(다음링크) 를 자기가 가짐.

        pre->link = newNode; // 이전 노드가 자기를 가르키게.
    }

    return;
};

void insertLast(nodeHeader *header, char *insertData)
{

    node *newNode = new node();

    strncpy_s(newNode->data, sizeof(newNode->data), insertData, sizeof(newNode->data) - 1);

    if (header->head == NULL)
    { // 리스트가 빈 경우
        header->head = newNode;
        newNode->link = NULL;
    }
    else
    {

        newNode->link = NULL; // == (*newNode).link = NULL    !!!!   즉, 화살표 연산자는 포인터 이름만으로 동작 하는 것  (포인터 이름 앞에 * 붙이면 X!!!)

        /*
        node *temp = new node(); // 마지막노드 탐색을 위한 임시 노드 생성

        temp = header->head; // 탐색 시작점 설정(head)

        while (temp->link != NULL)
            temp = temp->link;

        temp->link = newNode; // 얕은 복사이기 때문에 실제 temp 가 가르키는 Node에 적용이 됨

        delete temp; // 얕은 복사여도 temp만 지워지지 temp가 가르키는 값도 지워지지 않음.

        */  //ver3. 이미 만든 함수를 이용하여 메모리 관리 및 가독성 향상을 올림.   (요런식으로 바꾸면, delete 안쓰고 함수 없어지면 포인터 사라져서 관리 쉽지롱!)


        node *temp = _searchNode(header, (node*)NULL); //NULL이 link인 즉, 마지막 노드를 검색함.    궁금점 : (node*) 이렇게 강제 형변환, 나중에 ㄱㅊ은걸까?

        if(temp == NULL){
            cout << "마지막 노드 검색 실패, 작업 성공하지 못 했습니다." << endl;

            return;
        }

        temp -> link = newNode;

        return;
    }
};

bool _copyNode(node *destination, node *source)
{

    cout << sizeof(*destination) << endl;
    if (sizeof(*destination) != sizeof(*source))
    { // 각 포인터 들이 가르키는 구조체 크기가 다르면 중지 및 리턴처리.
        return false;
    }

    memcpy(destination, source, sizeof(destination)); // 구조체 메모리 자체를 복사.

    return true;
};


//여기서부터 return pointer를 어떻게 줘야할지 문제임.

node *_searchNode(nodeHeader *header, char *targetData)
{

    //node *result = new node(); // 결과를 저장할 노드 결과를 새로운 메모리를 만들어야(stack에 저장) 함수가 끝나도 사라지지 x

    //node *temp = new node(); // 탐색할 임시 노드

    node* temp = header -> head; //탐색의 임시 노드 설정 (스택에 저장되어, 함수가 끝나면 삭제되는 포인터  <포인터가 가르키는 노드는 삭제되지 X!>  )


    //temp = header->head; // 탐색 초기 설정

    while (strcmp(temp->data, targetData) != 0)
    {

        if (temp->link == NULL)
            return NULL; // 끝까지 탐색 했는데 없으면 NULL반환 및 종료   [이 구문이 먼저와야 오류 x]

        temp = temp->link;
    };

    /**
     * 같은 메모리를 가르키는 지 확인 하려면 ==
     * 내용을 확인하려면 strcmp
     */

    // copyNode ==  성공 : true, 실패 : false   그리고 result는 포인터라 그냥쓰면 주소, *result는 값임

    //  ver 1.
    // if (copyNode(result, temp))
    // {

    //     delete temp;

    //     return result;
    // }
    // else
    // {

    //     delete temp;
    //     delete result;
    //     return NULL;
    // } ver 1.

/*

    if (copyNode(result, temp))
    {

        delete temp;

        return result;
    }
    else
    {

        delete temp;
        delete result;
        return NULL;
    }

*///ver2. 그냥 copy나 strcmp 없이, 스택저장포인터하나를 return 하는 것으로 변경.

    return temp;




    /**
     * Q : new라서 메모리 해제 해야 하는데, 리턴을 하는 메모리는 해제 해야하나?
     * A : 해당 함수를 호출한 호출자에서 해제함.
     */

    /**temp는 주소값을 저장 했는데(얕은 복사) 왜 굳이 복사가 필요한 것임?
     * ㅇㅇ 그래서 그냥 줘도 된다. (대신 외부에서 수정이 가능하게 됨) ==> ver2. (+ 함수 내부에서만 쓰는건 new말고 다른 것)
     * 그냥 줄때 다른 함수에서 가르킨 걸 가르키는 포인터라면, 함수가 끝나도 남아있어서 ㅇㅋ
     * 
     * !! 로컬변수는 스택에,  new는 힙에 저장인데
     * 로컬변수는 함수 종료시 스택에서 해제, 하지만 스택에 할당된 포인터가 가르키는게 스택에 없으면 사라지지 X라서 임.
     * 
     * 힙은 따라서 사용자가 메모리 누수를 관리해야 하기 때문에, 새로운 new 방식 포인터보다 로컬 포인터를 만드는게 가성비다.
     * 
     */
};

node *_searchNode(nodeHeader *header, node *targetLink)
{
    //node *result = new node(); // 결과를 저장할 노드

    //node *temp = new node(); // 탐색할 임시 노드

    node *temp = header -> head; // 탐색 초기 설정

    while (temp->link != targetLink)
    {
        if (temp->link == NULL)
            return NULL; // 끝까지 탐색 했는데 없으면 NULL반환 및 종료   [이 구문이 먼저와야 오류 x]

        temp = temp->link;
    }

    return temp; //스택에 있는 포인터 리턴(함수가 끝나면 포인터는 사라지지만 가르키는 값은 힙에 있어 사라지지 않음.)

}

void printList(nodeHeader *header)
{

    // 리스트 오류 거르기.

    if (header->head == NULL)
        cout << "리스트가 비었습니다." << endl;
        return;

    //node *temp = new node(); // 노드를 출력할 임시 개체.

    
    node *temp = header->head; // 시작 노드의 주소값을 임시 개체에 저장.

    cout << "\n\n노드 헤더 출력\n"  << endl;

    while (temp != NULL || temp != nullptr) //ver3. 향상된 끝 노드 검출 로직. (마지막 노드까지 처리 가능함.)
    {

        cout << temp->data << endl; // 노드출력

        temp = temp->link; // 다ㅡ음 노드 이동
    }

    temp = nullptr; // 임시 노드 메모리 해제
    return;
};

void freeList(nodeHeader *header)
{

    if (header->head != NULL)
    { // 노드가 1개라도 있는 리스트만

        _freeList_recursiveExcute(header, header->head);
        // 재귀함수를 통해, 노드를 순차적으로 제거해감 + 포인터도 비움.
    }

    if (nullptr != header)
    {
        delete header;
        header = nullptr;
    } // 공통적으로 헤더 삭제.

    return;
}

void _freeList_recursiveExcute(nodeHeader *header, node *target)
{ // 재귀함수임.

    if (target->link != NULL)
        _freeList_recursiveExcute(header, target->link); // 가장 끝 노드까지 재귀 시키기

    if (nullptr != target)
    {
        delete target;
        target = nullptr;
    } // 포인터와 포인터가 가르치는 대상 안전삭제 (댕글링 포인터터 방지)
}

/**
 * new로 생성은, 포인터와 그 포인터가 가르키는 대상을 생성함.
 * delete로 해당 포인터를 제거 하게 되면, 포인터는 남고 가르키는 대상이 지워짐. 그리고 포인터는 아무것도 가르키지 않음.
 *
 * 포인터는 함수 종료 및 스코프가 끝나면 스택에 있는 메모리에서 "자동으로 해제됨"
 * 또한 포인터는 "직접 해제 할 수 없음."
 *
 * 따라서 new생성을 delete한다면, nullptr 이라는 NULL의 ptr버전을 사용하여 안전하게 제거 구문 추가가 필요(댕글링 포인터를 방지하려고고)
 *
 * [아래는 안전한 포인터 초기화 구문]
 * if (nullptr != Ptr) {
    delete Ptr;
    Ptr = nullptr;
}

 */

void deleteNode(nodeHeader *header, node *target)
{

    if(target == NULL || target == nullptr) return;  //ver3. 입력받은 target 이 null 일 수 있으므로, 확인절차.

    node *preNode = _searchNode(header, target); // new로 받을 코드를 새로 생성 하지 않아도 ㅇㅋ      수정 - 전 노드를 알아야 하기 때문에, target의 주소를 가지고 있는 노드를 검색함.
    if(!preNode) { // preNode == NULL 과 같은 의미 (NULL은 0을 의미)    ->  전 노드가 없으면 즉, 맨 처음 놈이면면
    
        header -> head = target -> link; //시작 지점 건내주고고

        // delete target;
        // target = nullptr;


    }else{ //전노드가 잇으면, 즉 중간 친구면
        
        
        preNode -> link = target -> link; //전껄로 인수인계     맨마지막 노드여도(다음이 NULL), 결국엔 NULL을 주니 상관 x

        // delete target;
        // target = nullptr;
            
    }

    delete target;
    target = nullptr; //ver3. 가독성 향상


    return;


    /**
     *
     * 1.node* preNode 로 리턴 값을 받았기에, 얕은 복사를 함. 따라서 delete preNode 하면 리턴값도 해제됨. (이후에 ptr = nullptr 사용)
     *
     * 2.파라미터가 *char 인데, 넘길 때 인자가 왜 char인가
     *
     * char을 그냥 쓰면 첫 주소를 의미 하기 때문이다.
     * 만약에 &char변수 해버리면 char변수의 전체 메모리 주소를 리턴.
     * 따라서 *char변수 출력하면, 맨 앞글자 하나만 출력됨
     * why : char변수 가 포인터 시작 첫 주소이니 이를 출력하는 연산자 * 를 붙이면 첫 글자가 나옴.
     *
     */
}
    







    /*

    --- 태스트 ---


#include <iostream>



int* test(int* ptr){
    
    
    int* returnPtr = ptr;
    
    return returnPtr;
    
    
}

int main()
{
    int* mainPtr = new int(3);
    
    int* cont = test(mainPtr);

    std::cout << *mainPtr << std::endl;   -> 3출력

    delete cont;
    
    std::cout << *mainPtr;  -> 이상한 값 출력 (포인터가 얕은 참조로 복사된 객체를 delete 함으로써 삭제됨을 알 수 있따.)

    return 0;
}

*/