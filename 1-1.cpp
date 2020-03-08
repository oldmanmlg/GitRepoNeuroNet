#include <iostream>
//��� ���������, ������ ����� ��� ���������� ����������
char*right;
char* start;
int num_bites;

void makeAllocator(size_t max_Size) { // ������ ��� null ptr ������� ������ ��������� ��� ���� ����
	start = (char*) std::malloc(max_Size);
	right = start;
	num_bites = max_Size;
	std::cout << "makeAllocator";
}

char* alloc(size_t size) {
	if (right + size > start + num_bites - 1) {
		std::cout << "nullptr";
		return nullptr;
	}
	right += size;
	char* tmp = right - int(size);
	return tmp;
}

void reset(void) {
	right = start;
}

int main() {
	makeAllocator(1024);
	char* p1 = alloc(100);
	char* p2 = alloc(200);
	//reset();
	char* p3 = alloc(1000);
	return 0;
}
