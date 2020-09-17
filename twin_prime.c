#include <stdio.h>
bool check_prime(int n){
	bool flag = true;
	int i = 0;
	if (n == 1){
		return 0;
	}
	for (i=2; i <= n/2; ++i){
		if (n % i == 0){
			flag = false;
			break;
		}
	}
	return flag;
}

bool check_twin_prime(int n){
	bool flag = false;
	if (check_prime(n) && (check_prime(n-2) || check_prime(n+2))){
		flag = true;
	}
	return flag;
}


int main(int argc, char* argv[]) {
	const char *filename = argv[1];
	FILE *file = fopen(filename, "r");
	int num = 0;
	while(!feof(file)){
		fscanf(file, "%d", &num);
		printf("%s\n", check_twin_prime(num) ? "yes" : "no");
	}
	fclose(file);
	return 0;
}

