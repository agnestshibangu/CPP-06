#include "Serializer.hpp"

int main() {
	Data data;

	data.name = "Alice";
	data.age = 30;
	data.next = nullptr;

	std::cout << "Data pointer: " << &data << std::endl;
	std::cout << "Data name: " << data.name << std::endl;
	std::cout << "Data age: " << data.age << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	Data* recovered = Serializer::unserialize(raw);
	std::cout << "Recovered pointer: " << recovered << std::endl;
	std::cout << "Recovered name: " << recovered->name << std::endl;
	std::cout << "Recovered age: " << recovered->age << std::endl;

	if (recovered == &data)
		std::cout << "✅ Success: The recovered pointer is the same as the data!" << std::endl;
	else
		std::cout << "❌ Error: The recovered pointer is different from the data." << std::endl;

	return 0;
}
