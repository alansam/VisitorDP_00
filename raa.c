#include "raa.h"

/*
 *  MARK:  initSystem()
 */
void initSystem(raaSystem * pSystem) {
  printf("In func %s()\n", __func__);
  pSystem->ID = 0u;
  pSystem->pNode = NULL;
  pSystem->pArc = NULL;
}

/*
 *  MARK:  initNode()
 */
raaNode * initNode(raaNode * pNode,
                   uint32_t uiId,
                   float * pfPosition) {
  printf("In func %s()\n", __func__);
  pNode->ID = uiId;

  return pNode;
}

/*
 *  MARK:  initArc()
 */
raaArc * initArc(raaArc * pArc,
                 uint32_t uiId,
                 raaNode * pNode0,
                 raaNode * pNode1,
                 float * pfPosition) {
  printf("In func %s()\n", __func__);
  pArc->ID = uiId;
  pArc->pNode0 = pNode0;
  pArc->pNode1 = pNode1;
  return pArc;
}

/*
 *  MARK:  addNode()
 */
void addNode(raaSystem * pSystem, raaNode * pNode) {
  printf("In func %s()\n", __func__);
  pSystem->pNode = pNode;
}

/*
 *  MARK:  addArc()
 */
void addArc(raaSystem * pSystem, raaArc * pArc) {
  printf("In func %s()\n", __func__);
  pSystem->pArc = pArc;
}

/*
 *  MARK:  visitNodes()
 */
void visitNodes(raaSystem * pSystem, nodeFunction * pNodeFunction) {
  printf("In func %s()\n", __func__);
  pNodeFunction(pSystem->pNode);
}

/*
 *  MARK:  visitArcs()
 */
void visitArcs(raaSystem * pSystem, arcFunction * pArcFunction) {
  printf("In func %s()\n", __func__);
  pArcFunction(pSystem->pArc);
}
