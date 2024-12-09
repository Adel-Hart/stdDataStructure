#ifndef __node_H__
#define __node_H__

typedef struct Node //연결 리스트의 노드
{
    /* data */
    char data[10];
    struct Node* link; //typedef struct 구문이 끝나지 않아, Node에 대한 포인터는, Node*이 아닌 struct Node*이다.
} node;


typedef struct{  //연결 리스트의 앞부분, !! 연결 리스트는 앞 부분이 있어야 한다 !!

    node* head;

} nodeHeader; //"익명 구조체" typedef와 구조체 별칭이 있으면, struct 이름 정의 안해도 ok이다.



#endif