#include <iostream>
#include <vector>

typedef int type;

int count(type num , std::vector<type> array){
	for(int i =0 ; i < array.size() ; i++){
		if (num == array[i]){
			for (int j= 1 ; j < array.size(); j++){
				if (array[j] != num){
					return j - i;
				}
			}
		}
	}
	return 0;
}


int main(){
	std::vector<type> array;
	int n;
	std::cout << "Specify amout of elements in array:\n";
	std::cin >> n;
	std::cout << "Input elements (remember they have to be sorted):\n";
	for (int i=0; i < n ; i++){
		int a;
		std::cin >> a;
		array.push_back(a);	
	}

	std::cout << "What element do you want to be counted:\n";
	type num;
	std::cin >> num;

	std::cout << count(num , array) << "\n";

	return 0;
}
