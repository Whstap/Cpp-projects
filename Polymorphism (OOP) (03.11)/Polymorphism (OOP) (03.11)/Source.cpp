#include "Figures.h"

int main() {

	Figure* fptr{};

	fptr = new Rectangle{ Brush{"green"}, Pen{"white", 5}, 5, 7 };

	fptr->output() << endl;

	Figure* fptrarr[2];
	fptrarr[0] = new Rectangle{ Brush{"green"}, Pen{"white", 5}, 5, 7 };
	fptrarr[1] = new Square{ Brush{"green"}, Pen{"white", 5}, 5 };

	for (int i = 0; i < 2; i++) {
		fptrarr[i]->output() << endl;
	}

	for (int i = 0; i < 2; i++) {
		delete fptrarr[i];
	}

	return 0;
}