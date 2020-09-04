//1. Продемонстрировать различные уровни инкапсуляции данных(указать комментарием) :
//	a.Отсутствие инкапсуляции(public свойства)
//	b.Инкапсуляция с помощью set / get
//	c.Инкапсуляция с помощью специализированных протоколов / методов
//	d.Инкапсуляция за счёт абстракций
//
//	p.s.использовать механизмы исключений, если нарушается инвариант или не соблюдаются пост / пред - условия
//
//	2. Продемонстрировать различные варианты инкапсуляции поведения
//	a.За счёт позднего связывания
//	b.Замена поведения(тут тоже используется позднее связывание)
//	c.Расширения поведения(тут тоже используется позднее связывание)

#include <iostream>

using namespace std;

enum SEX {
	u, m, f
};

class Student {
protected:
	float avg_score;

public:
	int age;//1.a

	Student(float avg_score, int age) {
		this->age = age;
		this->avg_score = avg_score;
	}

	virtual void Message() {//2.a
		cout << "student" << endl;
	}

	float get_avg_score() { //1.b
		return avg_score;
	}

	void add_avg_score(float num) {//1.c
		this->avg_score += num;
	}

	void recbook() {
		cout << "ive recbook" << endl; //2.b
	}
};

class Bad_Student :public Student {
protected:
	int num_of_debts;

public:

	Bad_Student(float avg_score, int age, int num_of_debts) :Student(avg_score, age) {
		this->age = age;
		this->avg_score = avg_score;
		this->num_of_debts = num_of_debts;
	}

	void Message() {//2.c
		cout << "Bad_student" << endl;
	}

	void set_num_of_bebts(int num_of_debts) {//1.b
		this->num_of_debts = num_of_debts;
	}
};

int main() {

	Student alex(4, 22);
	alex.Message();

	Bad_Student olex(4, 22, 2);
	olex.Message();
	olex.recbook();
	cout << olex.get_avg_score() << endl;
	olex.add_avg_score(1);
	cout << olex.get_avg_score() << endl;
}