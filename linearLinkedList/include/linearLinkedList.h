#ifndef __linearLinkedList_H__
#define __linearLinkedList_H__

#include "node.h"


nodeHeader* makeList(); //리스트 생성 함수   / 포인터를 리턴으로 하는 이유 -> 그냥 값 : 전달하려면 포인터 변환 거쳐야 해서 귀찮
void insertFirst(nodeHeader* header, char* insertData); //nodeHeader* header -> call by reference 즉 함수 내에서 원본을 가져옴(포인터로) 그래서 수정이 적용됨
void insertMiddle(nodeHeader* header,node* pre ,char* insertData);
void insertLast(nodeHeader* header, char* insertData);

void printList(nodeHeader* header);
void freeList(nodeHeader* header); //메모리 해제 함수
void freeList_recursiveExcute(nodeHeader* header, node* target); //메모리 해제에 쓰이는 재귀 함수수

void deleteNode(nodeHeader* header, node* target);

bool copyNode(node* saver, node* target);

node* searchNode(nodeHeader* header, char* targetData);

#endif