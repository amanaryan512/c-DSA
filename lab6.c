#include <stdio.h>
#include <stdlib.h>

struct node {
     int exp;
     int coeff;
     struct node* next;
};

void push(struct node **head_ref, int x,int y) {
     if (*head_ref == NULL) {
          struct node* new_node = (struct node*)malloc(sizeof(struct node));

          new_node->coeff =  x;
          new_node->exp = y;

          new_node->next  = NULL;
          *head_ref = new_node;
     }
     else {
          struct node* new_node = (struct node*)malloc(sizeof(struct node));

          new_node->coeff =  x;
          new_node->exp = y;

          new_node->next  = NULL;

          struct node* temp = *head_ref;
          while (temp->next != NULL) {
               temp = temp->next;
          }

          temp->next = new_node;
     }
}

void FindAddedPloynomial(struct node* poly1,struct node* poly2, struct node** poly) {
     while (poly1 && poly2) {
          struct node* new_node = (struct node*)malloc(sizeof(struct node));
          if(poly1->exp > poly2->exp) {
               new_node->exp = poly1->exp;
               new_node->coeff  = poly1->coeff;
               new_node->next  = NULL;
               poly1 = poly1->next;
          }
          else if(poly1->exp < poly2->exp) {
               new_node->exp = poly2->exp;
               new_node->coeff  = poly2->coeff;
               new_node->next  = NULL;
               poly2 = poly2->next;
          }
          else {
               new_node->exp = poly1->exp;
               new_node->coeff = poly1->coeff + poly2->coeff;
               new_node->next  = NULL;
               poly1 = poly1->next;
               poly2 = poly2->next;
          }
          if(*poly != NULL) {
               struct node* temp = *poly;
               while(temp->next != NULL) {
                    temp = temp->next;
               }
               temp->next = new_node;
          }
          else {
               *poly = new_node;
          }
     }

     while (poly1 || poly2) {
          struct node* new_node = (struct node*)malloc(sizeof(struct node));
          if(poly1) {
               new_node->exp = poly1->exp;
               new_node->coeff  = poly1->coeff;
               new_node->next  = NULL;
               poly1 = poly1->next;
          }
          if(poly2) {
               new_node->exp = poly2->exp;
               new_node->coeff  = poly2->coeff;
               new_node->next  = NULL;
               poly2 = poly2->next;
          }
          if(*poly != NULL) {
               struct node* temp = *poly;
               while(temp->next != NULL) {
                    temp = temp->next;
               }
               temp->next = new_node;
          }
          else {
               *poly = new_node;
          }
     }
}

void PrintPoly(struct node* node) {

     while(node != NULL) {
          printf("%d", node->coeff);
          if(node->exp > 1) {
               printf("X^%d", node->exp);
          }
          else if(node->exp == 1) {
               printf("X");
          }
          if (node->next != NULL) {
               printf("+");
          }
          node = node->next;
     }
}

int main() {
     struct node *Eq1 = NULL, *Eq2 = NULL; 
     int l1,l2;
     int i;
     int x,y;
     scanf("%d", &l1);
     for(i=0;i<l1;i++) {
          scanf("%d %d", &x,&y);
          push(&Eq1,x,y);
     }
     scanf("%d", &l2);
     for(i=0; i<l2; i++) {
          scanf("%d %d", &x,&y);
          push(&Eq2,x,y);
     }

     struct node* Eq = NULL;
     FindAddedPloynomial(Eq1,Eq2,&Eq);

     PrintPoly(Eq);

     return 0;
}
