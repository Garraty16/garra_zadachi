// objective: есть 2 объекта со своими частотами меняют значение по формуле
// система считает свое значение как произведение значений объектов и имеет свою собственную частоту
// Выводить 2, если значение системы четно, 1 - если четно, иначе - 0
#include <stdio.h>
#define MAX_VAL 10000
#define WORKING_TIME 100

// --- GLOBAL VAR ---
struct obj obj1, obj2, systemObj;
int time = 0, system_tact = 1;
int yes = 1; // 0 => stop working
// --- END OF GLOBAL VAR ---

// структура объекта
struct obj {
	int val;
	int n;
	int frequency;
	int fRemaining;
	
	// функция для расчета текущего значения объекта
	void (*calcVal)(struct obj *self);
} ;

// расчет val для объекта
void obj_calcVal(struct obj *self){
	self->val += self->n;
	if (self->val > MAX_VAL)
		self->val = 0;
}

// расчет val для системы
void system_calcVal(struct obj *self){
	self->val = obj1.val * obj2.val;
}

// ввод данных об объекте
void input_object_data(struct obj *object){
	printf("\nObject.n = ");
	scanf("%d", &object->n);
	printf("Object.frequency = ");
	scanf("%d", &object->frequency);
	object->val = 0;
	// frequency to tick
	object->fRemaining = object->frequency;
}

// четное - 2, неч. - 1, др. - 0
int calcEvenOdd(int number){
	int answ = 0;
	if (number != 0){
		if (number % 2 == 0)
			answ = 2;
		else
			answ = 1;
	}
	return answ;
}

void obj_tick(struct obj *object){
	// frequency event
	if (object->fRemaining == 0){
		object->fRemaining = object->frequency - 1;
		object->calcVal(object);
	}
	else
		object->fRemaining--;
}

void system_tick(struct obj *object){
	// frequency event
	if (object->fRemaining == 0){
		object->fRemaining = object->frequency - 1;
		object->calcVal(object);
		// write state of a system
		printf("\n%d) System.State = %d", system_tact, calcEvenOdd(object->val));
		system_tact++;
	}
	else
		object->fRemaining--;
}

// выполняется в каждый момент времени
void timeTick(){
	time++;
	obj_tick(&obj1);
	obj_tick(&obj2);
	system_tick(&systemObj);
	// выход из программы
	if (time > WORKING_TIME)
		yes = 0;
}

int main (int argc, char *argv[])
{
	// customization
	obj1.calcVal = obj_calcVal;
	obj2.calcVal = obj_calcVal;
	systemObj.calcVal = system_calcVal;
	
	// input data
	printf("--- Data Input ---");
	printf("\nObject 1:");
	input_object_data(&obj1);
	printf("\nObject 2:");
	input_object_data(&obj2);
	printf("\nSystem:");
	input_object_data(&systemObj);
	
	// working cycle
	while (yes == 1) {
		timeTick();	
	} 
	return 0;
}

// jane.laboratory@gmail.com/