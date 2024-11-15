#include "framework.h"


int main()
{

	srand(time(nullptr));


	Knight k1 = Knight(1500, 20);
	k1.PrintInfo();

	Goblin g1 = Goblin(50, 10, "Godiln1");
	Goblin g2 = Goblin(50, 10, "Godiln2");
	Goblin g3 = Goblin(50, 10, "Godiln3");
	Goblin g4 = Goblin(50, 10, "Godiln4");
	Goblin g5 = Goblin(50, 10, "Godiln5");
	Goblin g6 = Goblin(50, 10, "Godiln6");
	Goblin g7 = Goblin(50, 10, "Godiln7");
	Goblin g8 = Goblin(50, 10, "Godiln8");
	Goblin g9 = Goblin(50, 10, "Godiln9");
	Goblin g10 = Goblin(50, 10, "Godiln10");
	g1,g2,g3,g4,g6,g7,g8,g9,g10.PrintInfo();


	

	while (true)
	{
		g1.Attack(&k1);
		g2.Attack(&k1);
		g3.Attack(&k1);
		g4.Attack(&k1);
		g5.Attack(&k1);
		g6.Attack(&k1);
		g7.Attack(&k1);
		g8.Attack(&k1);
		g9.Attack(&k1);
		g10.Attack(&k1);
		k1.Attack(&g1);
		k1.Attack(&g2);
		k1.Attack(&g3);
		k1.Attack(&g4);
		k1.Attack(&g5);
		k1.Attack(&g6);
		k1.Attack(&g7);
		k1.Attack(&g8);
		k1.Attack(&g9);
		k1.Attack(&g10);


		k1.PrintInfo();
		g1, g2, g3, g4, g6, g7, g8, g9, g10.PrintInfo();


		if (k1.IsDead() || g1.IsDead());
			break;
	}





	return 0;
}
