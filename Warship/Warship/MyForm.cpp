#include "MyForm.h"
#include "fGame.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Warship;




public ref class Cell {
protected:
	int state;
public:
	Cell() {} //0 = free; 1=busy; 2=dead
	void set() { state = 0; }
	void show(fGame %F) { F.write(Convert::ToString(state)); }
	bool isFree() { return state > 0 ? false : true; }
	void setState(int s) { state = s; }
	int getState() { return state; }
};
public ref class Ship {
protected:
	int squares;
	int health;
	int x, y;
	int orient; //0 = H 1 = V
public:
	Ship() {}
	Ship(int n) {
		squares = n;
		health = n;
		orient = 0;
	}
	~Ship() {}
	void initShip(int n) {
		squares = n;
		health = n;
		orient = 0;
	}
	bool isAlive() { return health > 0 ? true : false; }
	void rotate() { (orient == 0) ? orient = 1 : orient = 0; }
	int getSize() { return squares; }
	int getOrient() { return orient; }



};
public ref class Field {

public:
	array< Cell^, 2 > ^cells;
	Field() {
		cells = gcnew array<Cell^, 2 >(10, 10);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cells[i, j]->set();
			}
		}
	}
	void show(fGame% f) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++)
			{
				cells[i, j]->show(f);
			}
			f.write("\n");
		}
		f.write("\n\n");
	}
	void placeTo(int x, int y, Ship %S) {
		int sz = S.getSize();
		if (S.getOrient() == 0 && (x + sz) < 10)  //for horizontal y=const
			for (int i = x; i <= x + S.getSize() - 1; i++) cells[y, i]->setState(1);

		else if (S.getOrient() == 1 && (y + sz) < 10) //for vertical x=const
			for (int i = y; i <= y + S.getSize() - 1; i++) cells[i, x]->setState(1);

	}
	bool isPlacable() {
		return 0;
	}
	void hit() {
	}

};
public ref class Player {
protected:
	fGame^ form;
	Field^ field;
	array< Ship^>  ^Fleet;
	array<int, 2> ^hitTable;
public:
	void initHitTable() {
		for (int i = 0; i<10; i++)
			for (int j = 0; j<10; j++)
				hitTable[i, j] = 0;
	};
	void isPlacable(Ship%) {

	}
	void initFleet() {
		Fleet[0]->initShip(1);
		Fleet[1]->initShip(2);
		Fleet[2]->initShip(3);
		Fleet[3]->initShip(4);
		Fleet[4]->initShip(5);

	}
	void randPlace() {
		int x, y;
		bool placed = false;
		while (!placed) {
			//x = 1+rand()%10;
			//y=1+rand()%10;
			if (field->cells[y, x]->getState() == 0) {

			}
		}
	}
	void placeShip(int x, int y, Ship% s) { field->placeTo(x, y, s); };
	void attack(int x, int y, Player% evil) {
		switch (evil.field->cells[y, x]->getState()) {
		case 0: form->write("miss");
		case 1: {form->write("hit"); evil.field->cells[y, x]->setState(2); }
		}

	}
	void hit(int x, int y) { field->cells[y, x]->setState(2); }
	Player() {}
	Player(fGame% s) {
		form = %s;
		initHitTable();
		initFleet();

	}
	~Player() {}
protected:

public:
	void hitOut() {
		for (int i = 0; i<10; i++) {
			for (int j = 0; j<10; j++) {
				form->write(System::Convert::ToString(hitTable[i, j]) + " ");
			}
			form->write("\n");
		}
		form->write("\n");
	}
	void attack(Player% P) {
		bool swtch = true;
		while (swtch) {
			//int x = rand()%10;
			//int y = rand()%10;
			//if(hitTable[y,x]==0){
			//P.hit(x,y);
			swtch = false;
			//}
		}


	}
};
public ref class GAME {
protected:
	Player^ You;
	Player^ Enemy;
public:
	GAME() {
		You = gcnew Player;
		Enemy = gcnew Player;
	}
	void start() {

	}
};

[STAThreadAttribute]
void main(array<String^>^ arg) {

	GAME^ Game = gcnew GAME();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Warship::MyForm form;
	Application::Run(%form);
}

