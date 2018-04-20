#ifndef COMPOSEMGR_H
#define COMPOSEMGR_H
#include "Predefine.h"
#include "Score.h"
#include "ScoreMgr.h"
#include "StudentMgr.h"
class ComposeMgr
{
	public:
		ComposeMgr();
		~ComposeMgr();
		int PrintArr(){scoMgr.PrintArr();}
		int Query();
		int Manage();
	protected:
		ScoreMgr scoMgr;
};

#endif
