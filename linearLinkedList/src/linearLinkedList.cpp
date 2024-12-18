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
#include <string.h>


nodeHeader* makeList(){

    nodeHeader* header = new nodeHeader();
    header -> head = NULL; //초기는 값이 비었음(NULL), 리스트만 생성 된 것

    return header;

};

void insertFirst(nodeHeader* header, char* insertData){

    node* newNode = new node();

    strncpy_s(newNode -> data, sizeof(newNode -> data), insertData, sizeof(newNode -> data) - 1); 
    //새로운 노드에 데이터 추가, 두 네번째 인자에 각 사이즈가 들어가므로, 복사하는 값을 최대값보다 -1 하여 마지막 \0을 유지함 
    //char* insertData 인 이유, char insertData == insertData[0]라서, char[]이 아닌 char임

    

    if(header -> head == NULL){ //리스트가 비었을때(처음에 넣기)

        newNode -> link = NULL; //첫 노드 다음이 없기에(리스트가 비어서) NULL
        
        header -> head = newNode; //리스트 시작 포인터를 새로만든(newNode)것으로 연결
    }
    else{ //리스트가 이미 있을 때 (처음 껄 바꿔 치기)
        
        newNode -> link = header -> head; //원래 첫 노드를 가르키기
        
        header -> head = newNode; //자기 가르키게 하기.
    }
};

void insertMiddle(nodeHeader* header,node* pre ,char* insertData){

    node* newNode = new node();

    strncpy_s(newNode -> data, sizeof(newNode -> data), insertData, sizeof(newNode -> data) - 1); 

    if(header -> head == NULL){ //빈 리스트 일 경우(자기가 처음이 되야함)

        header -> head = newNode;
        newNode -> link = NULL;


    }else if (pre -> link == NULL){ //마지막에 넣는 경우
    
        pre -> link = newNode;
        newNode -> link = NULL;
    
        
    }else{ //정상적인 경우 (딱 정 중앙에 넣는 경우)

        newNode -> link = pre -> link; //이전 노드가 가르키는 링크(다음링크) 를 자기가 가짐.
        
        pre -> link = newNode; //이전 노드가 자기를 가르키게.
    }
    

};

void insertLast(nodeHeader* header, char* insertData){

    node* newNode = new node();

    strncpy_s(newNode -> data, sizeof(newNode -> data), insertData, sizeof(newNode -> data) - 1); 

    if(header -> head == NULL){ //리스트가 빈 경우
        header -> head = newNode;
        newNode -> link = NULL;

    }else{

        newNode -> link = NULL;
        
        node** temp = new node*();
        temp = header -> head;

        while(temp -> link != NULL) temp = temp->link; //temp에 마지막 노드가 올때까지 반복.

        temp -> link = newNode; //temp 는 포인터기 때문에 실제 값이 수정 됨        

        delete temp; //임시 값 해제.

    }
};

void copyNode(node* saver, node* target){

    

};







