#pragma once

#include <stdio.h>
#include <stdint.h>

typedef struct raaSystem raaSystem;
typedef struct raaNode raaNode;
typedef struct raaArc raaArc;

struct raaSystem {
  uint32_t ID;
  raaNode * pNode;
  raaArc * pArc;
};

struct raaNode {
  uint32_t ID;
};

struct raaArc {
  uint32_t ID;
  raaNode * pNode0;
  raaNode * pNode1;
};

const static uint32_t csg_uiNode = 1;
const static uint32_t csg_uiArc = 2;

typedef void (nodeFunction) (raaNode * pNode);
typedef void (arcFunction) (raaArc * pArc);

void initSystem(raaSystem * pSystem);
raaNode * initNode(raaNode * pNode, uint32_t uiId,
                   float * pfPosition);
raaArc * initArc(raaArc * pArc, uint32_t uiId,
                 raaNode * pNode0, raaNode * pNode1,
                 float * pfPosition);

void addNode(raaSystem * pSystem, raaNode * pNode);
void addArc(raaSystem * pSystem, raaArc * pArc);

raaNode * nodeById(raaSystem * pSystem, uint32_t uiId);

void visitNodes(raaSystem * pSystem, nodeFunction * pNodeFunction);
void visitArcs(raaSystem * pSystem, arcFunction * pArcFunction);
