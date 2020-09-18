
struct num {
    int giga;
    int nanos[100];//one of uint32 stands for 9 decimal digits
};

int newNum(double a, struct num *N);

void printNum(struct num *N);