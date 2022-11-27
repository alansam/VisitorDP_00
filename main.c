#include <stdio.h>
#include <stdint.h>

#include "raa.h"

void nf0(raaNode * pNode);
void nf1(raaNode * pNode);
void af0(raaArc * pArc);
void af1(raaArc * pArc);

/*
 *  MARK:  main()
 */
int main(int argc, char const * argv[]) {
  printf("Visitor Design Pattern\n");

  raaSystem sys0;
  raaNode node0;
  raaNode node1;
  raaArc arc0;
  float node0_pos = 0.5f;
  float node1_pos = 1.5f;
  float arc0_pos = 10.0f;

  initSystem(&sys0);
  initNode(&node0, csg_uiNode, &node0_pos);
  initNode(&node1, csg_uiNode, &node1_pos);
  initArc(&arc0, csg_uiArc, &node0, &node1, &arc0_pos);
  addNode(&sys0, &node0);
  addArc(&sys0, &arc0);

  visitNodes(&sys0, nf0);
  visitArcs(&sys0, af0);

  visitNodes(&sys0, nf1);
  visitArcs(&sys0, af1);

  return 0;
}

/*
 *  MARK:  nf0()
 */
void nf0(raaNode * pNode) {
  printf("In func %s()\n", __func__);
  printf("Node ID: %5u\n\n", pNode->ID);
}

/*
 *  MARK:  nf1()
 */
void nf1(raaNode * pNode) {
  printf("In func %s()\n", __func__);
  printf("Node ID: %5u\n\n", pNode->ID * 2);
}

/*
 *  MARK:  af0()
 */
void af0(raaArc * pArc) {
  printf("In func %s()\n", __func__);
  printf("Arc ID: %5u\n"
         "@Node0: %p\n"
         "@Node1: %p\n\n",
         pArc->ID, pArc->pNode0, pArc->pNode1);
}

/*
 *  MARK:  af1()
 */
void af1(raaArc * pArc) {
  printf("In func %s()\n", __func__);
  printf("Arc ID: %5u\n"
         "@: %p\n"
         "@: %p\n\n",
         pArc->ID * 2, pArc->pNode0, pArc->pNode1);
}
