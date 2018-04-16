#ifndef COMPOSEMGR_H
#define COMPOSEMGR_H
#include "Predefine.h"
#include "Score.h"
#include "ScoreMgr.h"
class ComposeMgr
{
	public:
		ComposeMgr();
		~ComposeMgr();
		int PrintArr(){scoMgr.PrintArr();}
	protected:
		ScoreMgr scoMgr;
};

#endif
