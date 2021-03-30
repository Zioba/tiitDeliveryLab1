#include "biblio.h"
using namespace std;
bool find(SET* pbeg, int k) {
	SET* pv = pbeg;
	while (pv) {
		if (pv->key == k)break;
		pv = pv->right;
	}

	if (pv != NULL)
		return true;
	else
		return false;
}

//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

SET* remove(SET* pbeg, int k) {
	if (find(pbeg, k)) {
		if (!pbeg) return NULL;
		if (pbeg->key < k)
			pbeg->right = remove(pbeg->right, k);
		else {

			SET* r = pbeg->right;
			delete pbeg;
			if (!r) return NULL;

			return r;
		}

		return pbeg;
	}
	else return pbeg;

}
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

SET* insert(SET* p, int k)
{
	SET* TEMP = new SET(k);
	if (!p) return new SET(k);
	if (!find(p, k)) {
		if (k < p->key) {
			TEMP->right = p;
			return TEMP;
		}
		else
			p->right = insert(p->right, k);
	}
	return p;

}
//добавление элементов
string print(SET* A) {

	string S = "";
	SET* B = A;

	while (B != NULL) {// Вывод всех элементов
		S += to_string(B->key) + " ";
		B = B->right;
	}
	if (!S.empty())
		S.erase(S.end() - 1);
	return S;
}
//объединение множеств
SET* uni(SET* A, SET* B) {
	SET* C = NULL;
	while (A != NULL) {
		C = insert(C, A->key);
		A = A->right;
	}
	while (B != NULL) {
		C = insert(C, B->key);
		B = B->right;
	}
	return C;
}
//пересечение множеств
SET* cros(SET* A, SET* B) {
	SET* C = NULL;

	while (A != NULL) {
		if (find(B, A->key)) {
			C = insert(C, A->key);
		}
		A = A->right;
	}
	return C;
}

