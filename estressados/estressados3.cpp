#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool unico(vector<int> &vet, int num) {
	int contador{0};

	for (int valor : vet) {
		if (abs(valor) == abs(num) {
			contador++;
		}
		if (contador > 1) {
			return false;
		}
	}
	return true;
}

vector<int> sozinhos(vector<int> &vet) {
	vector<int> sozinhos{};

	for (int valor : vet) {
		if (unico(vet, valor)) {
			sozinhos.push_back(abs(valor));
		}
	}
	return sozinhos;
}

int ocorrencia(vector<int> vet, int num) {
	int contador{0};

	for (int stress : vet) {
		if (abs(stress) == abs(num)) {
			contador++;
		}
	}
	return contador;
}

int maior_ocorrencia(vector<int> vet) {
	int maior{0};

	for (int stress : vet) {
		if (ocorrencia(vet, stress) > maior) {
			maior = ocorrencia(vet, stress);
		}
	}
	return maior;
}

// usei a função do estressados 2
vector<int> exclusivos(const vector<int> &vet) {
	vector<int> exclusivos{};

	for (int i = 0; i < (int)vet.size(); i++) {
		if (find(exclusivos.begin(), exclusivos.end(), vet[i]) == exclusivos.end()) {
			exclusivos.push_back(vet[i]);
		}
	}
	return exclusivos;
}

vector<int> mais_recorrentes(vector<int> vet) {

	int mais_ocorrente{maior_ocorrencia(vet)};
	vector<int> recorrente{};

	for (auto i = vet.begin(); i != vet.end(); i++) {
		if (ocorrencia(vet, *i) == mais_ocorrente) {
			recorrente.push_back(abs(*i));
		}
		return exclusivos(recorrente);
	}
}

int conta_brigas(const vector<int> &vet) {
	int conta_briga{};

	for (int i = 1; i < ((int)vet.size()); i++) {
		if (vet[i] > 50 && (vet[i - 1] > 30 && vet[i + 1] > 30)) {
			conta_briga++;
		}
	}
	return conta_briga;
}

int apaziguados(const vector<int> &vet) {
	int brigas_apaziguadas{};

	for (int i = 1; i < ((int)vet.size()); i++) {
		if (vet[i] > 80 && (vet[i - 1] < 10 || vet[i + 1] < 10)) {
			brigas_apaziguadas++;
		}
	}
	return brigas_apaziguadas;
}

//Não soube como fazer as seguintes = quantos_times, maior_time, sem_time

int main() {
	vector<int> teste{1, 3, 4, 5, -1, -5, -5};
	cout << maior_ocorrencia(teste);
}
