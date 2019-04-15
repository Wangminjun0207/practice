struct Car
{
	char parkingNumber[5];		//停车场编号 
	char carNmber[10];			//车牌号 
	char carHost[10];			//车主姓名 
	char carType[6];			//车型 
	char parkDate[12];			//停车日期 
	char parkTime[6];			//停车时间 
	char takeDate[12];			//取车日期 
	char takeTime[6];			//取车时间 
	float parkCarCost;			//收取停车费用
	struct Car *next; 
};

